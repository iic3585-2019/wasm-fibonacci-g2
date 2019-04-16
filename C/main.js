Module.onRuntimeInitialized = onRuntimeInitialized;

function onRuntimeInitialized() {
  const foo = Module.cwrap('foo')

  console.log(foo())
}
