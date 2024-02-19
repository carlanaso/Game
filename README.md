*Hunt the Wumpus Game* 
- This is an assignment game from CS162 intro to computer Science

This game is called Hunt the Wumpus.

At the start of the game, the player is placed is randomly placed in a room in a cave grid. The cave grid is consisted of rooms. Each room can contain one or no event. The following are the event types:
Wumpus
Pits
Bats
Gold
The goal of the game is to acquire the gold, kill the Wumpus with your arrows, and go back to starting position to exit the cave.

Each turn, the player can either move, or fire an arrow.

When the player moves to a new room, the player can sense surrounding rooms (rooms directly adjacent to the room) using their "percept" ability; this means the player will be notified if any events are present in the surrounding rooms.

If the player fires an arrow, the player can choose which direction to shoot the arrow at. The arrow can travel 3 rooms, or less if it hits a wall (edge of the grid). If the arrow hits Wumpus, the Wumpus is killed. Otherwise, the Wumpus will be startled by the sound of the arrow and has 75% chance of moving to a different room. The player only carries 3 arrows, so if all the arrows are used up and the Wumpus is not killed, the game is over.

If the player goes to a room where Wumpus is, the player loses.
If the player goes to a room where there is a pit, the player falls into the pit and die.
If the player goes to a room where there is a bat, the player will be carried by the bat, and randomly dropped to a different room.
If the player goes to a room where there is gold, the player will pick up the gold. The gold can only be copied once.

Good luck!
