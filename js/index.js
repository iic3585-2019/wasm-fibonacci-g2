import("../crate/pkg").then(module => {
  const Chile = module.Country.new('Chile', 100);
  const Peru = module.Country.new('Peru', 200);
  const Argentina = module.Country.new('Argentina', 300);
  const Colombia = module.Country.new('Colombia', 400);
  

  Chile.addNeighbours(Peru);
  Chile.addNeighbours(Argentina);
  Chile.addNeighbours(Colombia);
  //Peru.addNeighbours(Chile);
  Peru.addNeighbours(Argentina);
  Peru.addNeighbours(Colombia);
  // Argentina.addNeighbours(Peru);
  // Argentina.addNeighbours(Chile);
  // Argentina.addNeighbours(Colombia);
  // Colombia.addNeighbours(Peru);
  // Colombia.addNeighbours(Argentina);
  // Colombia.addNeighbours(Chile);

  const map = module.Map.new();
  map.addCountry(Chile);
  //map.addCountry(Peru);
  //map.addCountry(Argentina);
  //map.addCountry(Colombia);

  //map.travel();
  // console.log(Chile);
  console.log(map);
  console.log(module.travel(map));

});
