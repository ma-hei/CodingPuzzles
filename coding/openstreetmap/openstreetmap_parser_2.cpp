#include <iostream>
#include "tinyxml.h"
#include "tinystr.h"
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <fstream>

using namespace std;

bool is_in_filter(string tag, vector<string> filter){
	for (string s : filter){
		if(s==tag){
			return true;
		}
	}
	return false;
}

int main(){

	TiXmlDocument doc( "node_info.osm" );
	bool load_okay = doc.LoadFile();

	unordered_map<string,pair<float,float> > all_nodes_positions;
	unordered_map<string,unordered_set<string> > all_nodes_next;

	vector<string> filter {"footway","residential","motorway", "trunk", "primary", "secondary", "tertiary", "service", "pedestrian", "road", "track", "path", "steps","living_street","unclassified","cycleway"};

	if (load_okay){
		TiXmlNode* osm = 0;
		osm = doc.FirstChild( "osm" );
		assert(osm);
		TiXmlElement* child = osm->FirstChildElement("node");
		string temp_id;
		float temp_lat;
		float temp_lon;
		while(child){
			temp_id = string(child->Attribute("id"));
			temp_lat = stof(string(child->Attribute("lat")));
			temp_lon = stof(string(child->Attribute("lon")));
			all_nodes_positions[temp_id] = pair<float,float>(temp_lat, temp_lon);
			child = child->NextSiblingElement("node");
		}
		cout<<"number nodes: "<<all_nodes_positions.size()<<"\n";
	}

	load_okay = doc.LoadFile("node_info.osm");
	int found_cnt = 0;
	int not_found_cnt = 0;
	if (load_okay){
		TiXmlNode* osm = doc.FirstChild( "osm" );
		assert(osm);
		TiXmlElement* child = osm->FirstChildElement("way");
		while (child){
			TiXmlElement* tag = child->FirstChildElement("tag");
			bool is_highway = false;
			bool is_building = false;
			while(tag){
				if (string(tag->Attribute("k"))=="building"){
					is_building = true;	
					break;
				}
				if (string(tag->Attribute("k"))=="area"){
					is_building = true;	
					break;
				}
				if (string(tag->Attribute("k"))=="highway"){
					if(is_in_filter(string(tag->Attribute("v")), filter))
						is_highway=true;
					else{
						cout<<string(tag->Attribute("v"))<<"\n";
					}
				}
				tag = child->NextSiblingElement("tag");
			}
			if (true){
				TiXmlElement* child_ = child->FirstChildElement("nd");
				TiXmlElement* child__ = NULL;
				string temp_id;
				while(child_){
					temp_id = string(child_->Attribute("ref"));
					if (all_nodes_positions.count(temp_id)>0) found_cnt ++;
					else not_found_cnt++;
					if(child__){
						all_nodes_next[string(child__->Attribute("ref"))].insert(string(child_->Attribute("ref")));
						all_nodes_next[string(child_->Attribute("ref"))].insert(string(child__->Attribute("ref")));
					}
					child__ = child_;
					child_ = child_->NextSiblingElement("nd");
				}
			}
			child = child->NextSiblingElement("way");
		}
	}	
	cout<<"found : not found "<<found_cnt<<" : "<<not_found_cnt<<"\n";

	string js_all_nodes_positions = "var all_points = {};";
	for (unordered_map<string,pair<float,float> >::iterator it = all_nodes_positions.begin(); it!=all_nodes_positions.end(); it++){
		if (all_nodes_next.count(it->first)==1){
			js_all_nodes_positions+="\n all_points[\""+it->first+"\"] = ["+to_string((it->second).first) +", "+to_string((it->second).second)+"];";
		}
	}
//	cout<<js_all_nodes_positions;
	string js_all_nodes_connections = "var all_nodes_next_nodes = {};";
	for (unordered_map<string, unordered_set<string> >::iterator it = all_nodes_next.begin(); it!=all_nodes_next.end(); it++){
		js_all_nodes_connections+="\n all_nodes_next_nodes[\""+it->first+"\"] = new Array();";
		for (unordered_set<string>::iterator it_ = (it->second).begin(); it_!= (it->second).end(); it_++){
			js_all_nodes_connections+="\n all_nodes_next_nodes[\""+it->first+"\"].push(\""+*it_+"\");";
		}
	}
//	cout<<js_all_nodes_connections<<"\n";
	//ofstream myfile;
	//myfile.open("all_nodes_info.js");
	//myfile<<js_all_nodes_positions<<"\n";
	//myfile<<js_all_nodes_connections<<"\n";

	ofstream myfile;
	myfile.open("nodes_0.js");
	//myfile<<"var all_points = {};\n";
	//myfile<<"var all_nodes_next_nodes = {};\n";
	
	unordered_map<string, unordered_set<string> >::iterator it = all_nodes_next.begin();
	unordered_map<string, int> seen;
	int file_count=0;
	int byte_total = 0;
	int node_count = 0;
	while (it!=all_nodes_next.end()){
		int bytes = 0;
		if (file_count>0){
			myfile.close();
			myfile.open("nodes_"+to_string(file_count)+".js");
			cout<<"new file.. "<<file_count<<"\n";
		}
		while(bytes<4000 && it!=all_nodes_next.end()){
			string node = it->first;
			if (seen.count(node)==0){
				pair<float,float> p = all_nodes_positions[node];
				string temp = "\n all_points[\""+node+"\"] = ["+to_string(p.first) +", "+to_string(p.second)+"];";
				seen[node] = 1;
				bytes+=temp.length();
				node_count++;
				myfile<<temp;
			}
			string temp ="\nall_nodes_next_nodes[\""+node+"\"] = new Array();";
			bytes+=temp.length();
			myfile<<temp;
			for (unordered_set<string>::iterator it_ = (it->second).begin(); it_ != (it->second).end(); it_++){
				string neighbor = *it_;
				if (seen.count(neighbor)==0){
					pair<float,float> p = all_nodes_positions[neighbor];
					string temp = "\n all_points[\""+neighbor+"\"] = ["+to_string(p.first) +", "+to_string(p.second)+"];";
					seen[neighbor] = 1;
					bytes+=temp.length();
					node_count++;
					myfile<<temp;
				}
				string temp = "\n all_nodes_next_nodes[\""+node+"\"].push(\""+neighbor+"\");";
				myfile<<temp;
				bytes+=temp.length();
			}
			it++;
			byte_total+=bytes;
		}
		file_count++;
		cout<<"files: "<<file_count<<"\n";
		cout<<"bytes: "<<byte_total<<"\n";
		cout<<"node count: "<<node_count<<"\n";
	}
}
