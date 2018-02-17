var app = angular.module("myApp", []);

app.controller("myCtrl", function($scope) {

    $scope.routeIDs = {};
    $scope.lastQueryTime = 0;
    $scope.projection;
    $scope.svg;    
    $scope.counter = 0;
   

    $scope.initProjection = function(width, height){

      var bounds = d3.geoBounds(streetsJson)
      var center = d3.geoCentroid(streetsJson)
      var distance = d3.geoDistance(bounds[0], bounds[1]);
      var scale = height / distance / Math.sqrt(2);

      $scope.projection = d3.geoMercator()
          .center(center)
          .scale(scale*1.2)
          .translate([width / 2, height / 2]);

    }

    $scope.drawMapFeature = function(featureName, pathData, pathProjection, color){
   
      var featureGroup = $scope.svg.append("g").attr("id",featureName);   

      featureGroup.selectAll('path')
        .data(pathData).enter()
        .append('path')
        .attr('d', pathProjection).attr("fill", "none").attr("stroke",color);
   
    }


    $scope.initMap = function(){

      map = document.getElementsByClassName("map")[0];
      var width = map.offsetWidth;
      var height = map.offsetHeight;

      $scope.initProjection(width, height);
    
      var path = d3.geoPath()
          .projection($scope.projection);

      $scope.svg = d3.select(".map")
        .append("svg")
        .attr("width", width)
        .attr("height", height);
 
      $scope.drawMapFeature("streets", streetsJson.features, path, "#000");
      $scope.drawMapFeature("arteries", arteriesJson.features, path, "#F00");
      $scope.drawMapFeature("freeways", freewaysJson.features, path, "#0FF");
      $scope.drawMapFeature("neighborhoods", neighborhoodsJson.features, path, "#000");

    }     

    $scope.updateVehicles = function(serverResponse){

      vehicleData = JSON.parse(serverResponse);

      $scope.lastQueryTime = vehicleData.lastTime["time"];

      if (typeof vehicleData.vehicle!=='undefined'){
        var vehicles = $scope.svg.selectAll("circle")
                           .data(vehicleData.vehicle, function(d) { return d["id"];});
      
        var t = d3.transition().duration(750);
        vehicles.attr("r", "4px")
          .attr("fill", "red")
          .transition(t)
          .attr("fill", "blue")
          .attr("cx", function(d) { return $scope.projection([d["lon"],d["lat"]])[0]; })
          .attr("cy", function(d) {return $scope.projection([d["lon"],d["lat"]])[1];})
        
        vehicles.enter()
          .append("circle")
          .attr("fill", "blue")
          .attr("r", "4px")
          .attr("cx", function(d) { return $scope.projection([d["lon"],d["lat"]])[0]; })
          .attr("cy", function(d) { return $scope.projection([d["lon"],d["lat"]])[1]; })
          .attr("class", function(d) { return "route_"+d["routeTag"];})
          .style("opacity", function(d) { return $scope.routeIDs[d["routeTag"]]==true ? 1 : 0; } );
      }   
 
    }
 
    $scope.toggleRoute = function(r){
      var class_label = ".route_"+r;
      d3.selectAll(class_label).style("opacity", $scope.routeIDs[r]==true ? 1 : 0);
    }

    $scope.initCheckboxesAndVehicles = function(serverResponse){
      
      vehicleData = JSON.parse(serverResponse);
      for (var i=0; i<vehicleData.vehicle.length;i++){
        console.log(vehicleData.vehicle[i]["routeTag"]);
        var routeTag = vehicleData.vehicle[i]["routeTag"];
        $scope.routeIDs[routeTag] = true;
      }
      $scope.$apply();
      $scope.updateVehicles(serverResponse);
    }
    
    $scope.httpGetAsync = function(url, callback){
      var xmlHttp = new XMLHttpRequest();
      xmlHttp.onreadystatechange = function() { 
        if (xmlHttp.readyState == 4 && xmlHttp.status == 200)
            callback(xmlHttp.responseText);
      }
      xmlHttp.open("GET", url, true); // true for asynchronous 
      xmlHttp.send(null);
    }


    $scope.startAnimation = function(){
      
      $scope.httpGetAsync("http://webservices.nextbus.com/service/publicJSONFeed?command=vehicleLocations&a=sf-muni&t=0", $scope.initCheckboxesAndVehicles);
      d3.interval(function() {
        $scope.httpGetAsync("http://webservices.nextbus.com/service/publicJSONFeed?command=vehicleLocations&a=sf-muni&t="+$scope.lastQueryTime, $scope.updateVehicles);
      }, 1500);
 
    }
 
    $scope.init = function(){
      $scope.initMap();
      $scope.startAnimation();
    }

   
});
