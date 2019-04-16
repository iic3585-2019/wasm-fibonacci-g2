import("../crate/pkg").then(module => {
  const Chile = module.Country.new(1, 'Chile');
  const Peru = module.Country.new(2, 'Peru');
  const Argentina = module.Country.new(3, 'Argentina');
  const Colombia = module.Country.new(4, 'Colombia');
  // const Rusia = module.Country.new(5, 'Rusia');
  // const England = module.Country.new(6, 'England');
  //const Japon = module.Country.new(7, 'Japon');
  //const Usa = module.Country.new(8, 'Usa');
  //const Germany = module.Country.new(9, 'Germany');


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
      }
    }
  }

  console.log(values);

  const map = module.Map.new();
  map.addCountry(Chile);
  map.addCountry(Peru);
  map.addCountry(Argentina);
  map.addCountry(Colombia);
  // map.addCountry(Rusia);
  // map.addCountry(England);
  // map.addCountry(Japon);
  // map.addCountry(Usa);
  // map.addCountry(Germany);


  console.log(module.travel(map));

});
