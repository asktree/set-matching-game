type card;
type set = (card, card, card);
type player = string;
type match = (player, set);
type deck = list(card);
type board = list(card);

type gameState = {
  board,
  deck,
  matches: list(match),
};


let is_valid: set => bool;
let initialize_game: unit => gameState;

let match_set: (match, gameState) => gameState;
let deal_more: gameState => gameState;

let card_as_tuple: card => (int, int, int, int);