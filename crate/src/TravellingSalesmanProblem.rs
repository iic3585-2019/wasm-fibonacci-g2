pub struct Country {
    name: char,
    neighbours: Vec<Country>,
    cost: u32,
    visited: bool,
}

impl Country {
    pub fn new(name: char, cost: u32) -> Country {
        Country {
            name: name,
            neighbours: Vec::new(),
            cost: cost,
            visited: false,
        }
    }
}

pub struct Map {
    countries: Vec<Country>,
}

impl Map {
    pub fn new() -> Map {
        Map {
            countries: Vec::new(),
        }
    }

    pub fn travel(&mut self){
        let mut initial = self.countries[0];
        let mut actual = initial;
        let mut cost = 0;
        while actual.visited == false {
            actual.visited = true;
            let mut min = -1;
            let mut index = -1;
            for i in 0..actual.neighbours.len() {
                if actual.neighbours[i].visited == false {
                    if min == -1 {
                        min = actual.neighbours[i].cost;
                        index = i;
                    }
                    else if actual.neighbours[i].cost < min {
                        min = actual.neighbours[i].cost;
                        index = i;
                    }
                }
            }
            if index != -1 {
                //println!("Se viaja desde {}, a {}, con un costo de {}", actual.name, actual.neighbours[index].name, actual.neighbours[index].cost)
                actual = actual.neighbours[index];
                cost += actual.cost;
            }
        }
        //println!("Se viaja desde {}, a {}, con un costo de {}", actual.name, initial.name, initial.cost)
        cost += initial.cost;
        //println!("El costo total del viaje fue de {}", cost);
    }
}
