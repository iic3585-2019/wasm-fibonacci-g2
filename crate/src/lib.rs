use wasm_bindgen::prelude::*;

// When the `wee_alloc` feature is enabled, use `wee_alloc` as the global
// allocator.
#[cfg(feature = "wee_alloc")]
#[global_allocator]
static ALLOC: wee_alloc::WeeAlloc = wee_alloc::WeeAlloc::INIT;

// Called by our JS entry point to run the example.
#[wasm_bindgen]
pub fn run() -> Result<(), JsValue> {
    set_panic_hook();

    let window = web_sys::window().expect("should have a Window");
    let document = window.document().expect("should have a Document");

    let p: web_sys::Node = document.create_element("p")?.into();
    p.set_text_content(Some("Hello from Rust, WebAssembly, and Webpack!"));

    let body = document.body().expect("should have a body");
    let body: &web_sys::Node = body.as_ref();
    body.append_child(&p)?;

    Ok(())
}

#[wasm_bindgen]
#[derive(Clone)]
pub struct Country {
    id: i32,
    name: char,
    neighbours: Vec<Country>,
    cost: i32,
    visited: bool,
}

#[wasm_bindgen]
impl Country {
    pub fn new(id: i32, name: char, cost: i32) -> Country {
        Country {
            id: id,
            name: name,
            neighbours: Vec::new(),
            cost: cost,
            visited: false,
        }
    }
    pub fn setVisited(&mut self) {
        self.visited = true;
    }
    pub fn addNeighbours(&mut self, country: Country) {
        self.neighbours.push(country);
    }
    pub fn cloned(&self) -> Country {
        return self.clone();
    }
}

#[wasm_bindgen]
pub struct Map {
    countries: Vec<Country>,
}

#[wasm_bindgen]
impl Map {
    pub fn new() -> Map {
        Map {
            countries: Vec::new(),
        }
    }
    pub fn addCountry(&mut self, country: Country) {
        self.countries.push(country);
    }
}

#[wasm_bindgen]
pub fn travel(mut map: Map) -> i32{
    let initial = map.countries[0].clone();
    let mut actual = initial.clone();
    let mut cost: i32 = 0;
    while actual.visited == false {
        actual.setVisited();
        let preview = actual.clone();
        for a in 0..map.countries.len(){
            for b in 0..map.countries[a].neighbours.len(){
                if map.countries[a].neighbours[b].id == preview.id{
                    map.countries[a].neighbours[b].setVisited();
                }
            }
        }
        let mut min: i32 = -1;
        let mut index: i32 = -1;
        for i in 0..actual.neighbours.len() {
            if actual.neighbours[i].visited == false {
                if min == -1 {
                    min = actual.neighbours[i].cost;
                    index = i as i32;
                }
                else if actual.neighbours[i].cost < min {
                    min = actual.neighbours[i].cost;
                    index = i as i32;
                }
            }
        }
        if index != -1 {
            let newIndex = index as usize;
            actual = actual.neighbours[newIndex].clone();
            for c in 0..map.countries.len(){
                if actual.id == map.countries[c].id{
                    actual = map.countries[c].clone();
                }
            }
            cost = cost + actual.cost;
        }
    }
    //println!("Se viaja desde {}, a {}, con un costo de {}", actual.name, initial.name, initial.cost)
    let finalCost:i32 = cost + initial.cost;
    //println!("El costo total del viaje fue de {}", finalCost);
    return finalCost;
}


fn set_panic_hook() {
    // When the `console_error_panic_hook` feature is enabled, we can call the
    // `set_panic_hook` function to get better error messages if we ever panic.
    #[cfg(feature = "console_error_panic_hook")]
    console_error_panic_hook::set_once();
}
