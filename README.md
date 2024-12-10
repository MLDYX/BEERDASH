# **BEERDASH**

**BEERDASH** is a dynamic platformer game inspired by the popular title **Geometry Dash**, where the player's task is to jump over obstacles, collect stars, and reach the end of each level. The game features various maps and a rating system based on level completion performance, offering hours of fun.

---

## **Game Features**
- **Collision detection:** Precise detection of collisions between the player, obstacles, and other objects.
- **Three unique themed maps:**
  - **Summer**
  - **Autumn**
  - **Winter**
- **Star collection:** Each map contains stars that increase the completion rating (from 2.0 to 5.0).
- **Custom game menu:** A manually implemented menu for map selection.
- **Dynamic camera:** A smooth camera system following the player.
- **Progress saving:** A system that tracks collected stars for each map.

---

## **Requirements**
- Operating system: Windows
- Installed libraries:
  - SDL2
  - SDL_image
  - SDL_mixer
  - SDL_ttf
- A C++ compiler (e.g., GCC or Visual Studio)

---

## **Installation**
1. Clone the repository:
   ```bash
   git clone https://github.com/MLDYX/beerdash.git
   cd beerdash
   ```
2. Install the required SDL2 libraries.
3. Compile the project:
   ```bash
   g++ -o beerdash Main.cpp WindowManager.cpp GameObjects.cpp Maps.cpp Stars.cpp -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf
   ```
4. Run the game:
   ```bash
   ./beerdash
   ```

---

## **Controls**
- **SPACE** – Jump
- **ENTER** – Confirm selection in the menu
- **RIGHT ARROW** – Change map in the menu
- **ESC** – Exit the game

---

## **Project Structure**
The project is modularized for better scalability and maintenance:
- `Main.cpp` – The main game loop and core logic.
- `WindowManager` – Handles window rendering and object display.
- `GameObject` – Represents game entities like obstacles, the player, and stars.
- `Maps` – Functions for loading maps and placing objects in levels.
- `Stars` – Manages star collection and progress saving.
- `Vector2` – A simple structure for object positioning.

---

## **Future Plans**
- Add more maps.
- Introduce new obstacle types and mechanics.
- Expand the save system and player statistics.
- Support for other platforms.

---

## **License**
This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

---

## **Contact**
For questions or suggestions about the game, reach out:
- Author: **Wiktor Rzepka**
- Email: wiktor.rzepka@icloud.com

---

**BEERDASH** – jump, collect stars, and have fun! 🎮🍺
