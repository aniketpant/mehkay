// generate a random string
function randomGenerator(length)
{
    var characterSet = 'abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ123456789';
    var count = characterSet.length;
    var stringSet = [];
    for (var i = 0; i < length; i++) {
        stringSet.push(characterSet[parseInt(Math.random() * (count + 1))]);
    }

    return stringSet.join('');
}

console.log(randomGenerator(10));
console.log(randomGenerator(20));
