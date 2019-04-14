import Route from '@ember/routing/route';

const importObject = {
  imports: { imported_func: arg => console.log(arg) }
};

export default Route.extend({
  init () {
    WebAssembly.instantiateStreaming(fetch('fibonacci_wasm.wasm'), importObject).then(obj => {
      const fib = obj.instance.exports.fibonacci(44);
      alert(fib);
    });
  }
});
