// https://stackoverflow.com/questions/53602955/using-emscripten-how-to-get-c-uint8-t-array-to-js-blob-or-uint8array

Module.onRuntimeInitialized = onRuntimeInitialized;

function Int32ArrayFromHeap(pointer, length) {
  return new Int32Array(Module.HEAP32.buffer, pointer, length);
}

function MallocInt32Array(array) {
  _array = new Int32Array(array.length)
  for (let i = 0; i < array.length; i++) _array[i] = array[i]
  buffer = Module._malloc(_array.length * _array.BYTES_PER_ELEMENT)
  Module.HEAP32.set(_array, buffer >> 2)

  return buffer;
}

function appendToArray(array, number) {
  const _appendToArray = Module.cwrap('appendToArray', 'Int32Array', ['number', 'number', 'number'])

  const buffer = MallocInt32Array(array);

  const newArrayPointer = _appendToArray(buffer, array.length, number);

  return Int32ArrayFromHeap(newArrayPointer, array.length + 1);
}

function insertToArray(array, number, position) {
  const _insertToArray = Module.cwrap('insertToArray', 'Int32Array', ['number', 'number', 'number', 'number'])

  const buffer = MallocInt32Array(array);

  const newArrayPointer = _insertToArray(buffer, array.length, number, position);

  return Int32ArrayFromHeap(newArrayPointer, array.length + 1);
}

function deleteFromArray(array, position) {
  const _deleteFromArray = Module.cwrap('deleteFromArray', 'Int32Array', ['number', 'number', 'number'])

  const buffer = MallocInt32Array(array);

  const newArrayPointer = _deleteFromArray(buffer, array.length, position);

  return Int32ArrayFromHeap(newArrayPointer, array.length - 1);
}

function concatenateArrays(leftArray, rightArray) {
  const _concatenateArrays = Module.cwrap('concatenateArrays', 'Int32Array', ['number', 'number', 'number', 'number'])

  const leftBuffer = MallocInt32Array(leftArray);
  const rightBuffer = MallocInt32Array(rightArray);

  const newArrayPointer = _concatenateArrays(leftBuffer, leftArray.length, rightBuffer, rightArray.length);

  return Int32ArrayFromHeap(newArrayPointer, leftArray.length + rightArray.length);
}

function onRuntimeInitialized() {
  let buffer;

  console.log('Append 5 to [0, 1, 2, 3, 4]:')
  buffer = appendToArray([0, 1, 2, 3, 4], 5)
  console.log(buffer)

  console.log('Insert 5 to [0, 1, 2, 3, 4] in 3:')
  buffer = insertToArray([0, 1, 2, 3, 4], 5, 3)
  console.log(buffer)

  console.log('Delete 3 from [0, 1, 2, 3, 4]:')
  buffer = deleteFromArray([0, 1, 2, 3, 4], 3)
  console.log(buffer)

  console.log('Concatenate [0, 1, 2, 3, 4] and [5, 6, 7, 8, 9]:')
  buffer = concatenateArrays([0, 1, 2, 3, 4], [5, 6, 7, 8, 9])
  console.log(buffer)
}
