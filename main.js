function Dark() {
  var element = document.body;
  element.classList.toggle("dark-mode");
  if (element.classList.contains("dark-mode")) {
    console.log("Dark mode is enabled");
  } else {
    console.log("Dark mode is disabled");
  }
}

const cardbuttons = document.getElementsByClassName('card__button');
var itemCount = 0;
const itemCounter = document.getElementById('ItemCounter');


console.log(cardbuttons[1]);
let sum = 0;

for (let i = 0; i < cardbuttons.length; i++) {
  cardbuttons[i].addEventListener('click', function () {
    console.log(itemCount);
  });
}


function counter() {
  itemCount++;
  itemCounter.innerText = itemCount;

}

const removefromcart = document.getElementsByClassName('del');
for (let i = 0; i < removefromcart.length; i--) {
  removefromcart[i].addEventListener('click', function () {
    console.log(itemCount);
  });
}

function verwijder() {
  itemCount--;
  itemCounter.innerText = itemCount;
  if (itemCount < 0) {
    itemCount = 0;
    itemCounter.innerText = itemCount;
  }
}