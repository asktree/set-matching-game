type value = int;
type card = list(value);
type set = (card, card, card);
type player = string;
type match = (player, set);
type deck = list(card);
type board = list(card);

type gameState = {
  board: board,
  deck: deck,
  matches: list(match)
}

exception SpecificationError(string);

let is_valid_trait = (x:value, y:value, z:value) => ((x == y && y == z) || (x != y && y != z && z != x))

let rec is_valid = (s) => {
  switch (s) {
  | ([], [], []) => true
  | ([xh, ...xt], [yh, ...yt], [zh, ...zt]) => is_valid_trait(xh, yh, zh) && is_valid((xt, yt, zt))
  | _ => raise(SpecificationError("argument is not a valid set"))
  }
}

let card_as_tuple = (c:card) => {
  switch (c) {
  | [v1, v2, v3, v4] => (v1, v2, v3, v4)
  | _ => raise(SpecificationError("card does not have exactly four values"))
  }
}

let set_contains = (s:set, c:card) => {
  switch (s) {
  | (c, _, _) => true
  | (_, c, _) => true
  | (_, _, c) => true
  | (_, _, _) => false
  }
}

let deal_more = (state:gameState) => {
  switch (state.deck) {
  | [] => state
  | [h1, h2, h3, ...tl] =>
    let new_board = [h1, h2, h3, ...state.board];
    {...state, board:new_board, deck:tl}
  | [_, _] => raise(SpecificationError("deck has 2 cards remaining which shouldn't be possible"))
  | [_] => raise(SpecificationError("deck has 1 cards remaining which shouldn't be possible"))
  }
}

let match_set = ((p, s):match, state:gameState) => {
  switch (is_valid(s)) {
  | false => state
  | true => 
    let new_board = List.filter(set_contains(s), state.board);
    if (List.length(new_board) != (List.length(state.board) - 3)) {
      raise(SpecificationError("not all cards of the set are on the board"))
    };
    let intermediate_state = {...state, board:new_board};
    deal_more(intermediate_state)
  }
}

let rec cart

let initialize_deck = ()

let initialize_game = () => {

}