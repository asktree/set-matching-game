type value = First | Second | Third;
type card = list(value);
type set = (card, card, card);
type player = string;
type match = (player, set);
type deck = list(card);
type board = list(card);

type gameState = {
  board: board,
  deck: deck,
  matches: list(match);
}
type msg = string;

let is_valid_trait = (x:value, y:value, z:value) => ((x == y && y == z) || (x != y && y != z && z != x))

let rec is_valid = (s) => {
  switch (s) => {
  | ([], [], []) => true
  | ([xh, ...xt], [yh, ...yt], [zh, ...zt]) => is_valid_trait(xh, yh, zh) && is_valid((xt, yt, zt))
  }
}
