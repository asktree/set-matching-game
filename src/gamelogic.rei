type card;
type set;
type player;
type match = (player, set);
type deck = list(card);
type board = list(card);

type gameState = {
  board: board,
  deck: deck,
  matches: list(match);
}
type msg = string;

let is_valid: set => bool;
let initialize_game: unit => gameState;

let match_set: (match, gameState) => (msg, gameState)
let deal_more: gameState => gameState;

let set_as_tuple: set => (card, card, card)
let card_as_tuple: card => (int, int, int)