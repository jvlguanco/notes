let firstCard, secondCard, sum;
let cards = [];
let hasBlackJack, isAlive;
let message = "";
let currentCards = "";
let i = 2;

let messageEl = document.getElementById("message-el");
let sumEl = document.getElementById("sum-el");
let cardsEl = document.getElementById("cards-el");
let newGameBtn = document.getElementById("start-btn");


function startGame(){
    cards = []
    hasBlackJack = false;
    isAlive = true;
    currentCards = "";

    firstCard = Math.random() * 10 + 2;
    cards.push(Math.trunc(firstCard));
    secondCard = Math.random() * 10 + 2;
    cards.push(Math.trunc(secondCard));

    sum = Math.trunc(firstCard) + Math.trunc(secondCard)
    newGameBtn.textContent = "New Game";

    for (i = 0; i < cards.length; i++) {
        currentCards += cards[i] + " ";
    }
    
    renderGame();
}

function renderGame(){
    if (sum <= 20) {
        message = "Do you want to draw a new card?";
    } else if (sum === 21) {
        message = "You've got Blackjack!";
        hasBlackJack = true;
    } else {
        message = "You're out of the game!";
        isAlive = false;
    }

    for (i; i < cards.length; i++) {
        currentCards += cards[i] + " ";
    }

    messageEl.textContent = message;
    sumEl.textContent = "Sum: " + sum;
    cardsEl.textContent = "";
    cardsEl.textContent = "Cards: " + currentCards;

    for (let i = 0; i < counter; i++) {
        cardsEl.textContent += cards[i] + " ";
    }
}

function newCard(){
    if (isAlive === true && hasBlackJack === false) {
        let card = Math.random() * 10 + 2;
        cards.push(Math.trunc(card));
        sum += Math.trunc(card);
        renderGame();
    }
    console.log(cards);
}

function stand(){
    if (isAlive === true && hasBlackJack === false) {
        isAlive = false;
        message = "Stand with " + sum + " ! You're out of the game! Start New Game!";
        messageEl.textContent = message;
    }
}