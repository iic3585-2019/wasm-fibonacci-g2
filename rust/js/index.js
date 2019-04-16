import("../crate/pkg").then(module => {
  const Chile = module.Country.new(1, 'Chile', 100);
  const Peru = module.Country.new(2, 'Peru', 200);
  const Argentina = module.Country.new(3, 'Argentina', 300);
  const Colombia = module.Country.new(4, 'Colombia', 400);

  const countries = [Chile, Peru, Argentina, Colombia];

  function randomInt() {
    return Math.floor(30 + Math.random()*10);
  }

  const values = [];


  
  for (const country of countries) {
    for (const neighbour of countries) {
      if (country != neighbour){
        const value = randomInt();
        values.push(value);
        country.addNeighbours(neighbour.cloned(), value);
        console.log(country);
        console.log(neighbour);
        console.log(value);
      }
    }
  }

  console.log(values);

  // Chile.addNeighbours(Peru.cloned());
  // Chile.addNeighbours(Argentina.cloned());
  // Chile.addNeighbours(Colombia.cloned());
  // Peru.addNeighbours(Chile.cloned());
  // Peru.addNeighbours(Argentina.cloned());
  // Peru.addNeighbours(Colombia.cloned());
  // Argentina.addNeighbours(Peru.cloned());
  // Argentina.addNeighbours(Chile.cloned());
  // Argentina.addNeighbours(Colombia.cloned());
  // Colombia.addNeighbours(Peru.cloned());
  // Colombia.addNeighbours(Argentina.cloned());
  // Colombia.addNeighbours(Chile.cloned());

  const map = module.Map.new();
  map.addCountry(Chile);
  map.addCountry(Peru);
  map.addCountry(Argentina);
  map.addCountry(Colombia);

  //map.travel();
  // console.log(Chile);
  console.log(map);
  console.log(module.travel(map));

});
