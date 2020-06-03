# SDLroguelike
a roguelike dungeon thing made with sdl.


This project requires the SDL2 developer framework to be installed in the system to run.


This project focuses on side scroller gameplay and will feature procedural terrain generation much like terraria.


# SDLRoguelike

SDLRoguelike (lacking official name) is a game written without the use of a pre-existing game engine that will feature procedural terrain generation.




```
Give examples
```

## Getting Started

### Prerequisites

  - SDL2
  - SDL Image
  - Either and IDE that supports C++ or a working non-integrated setup.

### Instructions
Clone the project while making sure to have the SDL2 Development libraries in your frameworks. Since this project uses both the base SDL library and SDL Image, both libraries must be downloaded separately from [the SDL website](https://www.libsdl.org/download-2.0.php). 

Alternatively, use the command (INSERT COMMAND HERE I FORGOT IT) if for some reason the website downloads do not work.

Since this project was made without the use of an IDE (so far), you will need to manually link/set the libraries in your respective environments.

<b>This project has been soley tested on a Macbook pro and, at this point in time, may not function on devices with a different operating system.</b>

## Running the tests

At this point in time, it is only necessary to compile and debug the project.

 <b> no deployment as of now</b>

## Built With

*SDL2 and all associated Libraries

## Contributing

- Mauckc

## Versioning

no actual versions as of yet

## Authors

- Ryan A

## License

idk what this is but probably creative commons

## Acknowledgments
* Those who helped my sucky code work.
* Inspired by: Terraria


## Method Description

### Various Getting & Setting Methods:

Get or set the indicated member of an object generally by mean of pointer reference.

### Update() and Render() 

Virtual Methods that render each object which can be overriden for special cases.

### HandleInput() 

Handles all imput and returns a list of InputEvents that will result in corresponding actions.

### CheckAABBCollisions(obj1, obj2) 

Checks whether any two objects with a bounding box are colliding and if so responds accordingly.


## Improving Efficiency:

### Rendering & Updating Caches:
- Add Lists of objects that need to be rendered/updated and pass them to a global render/update method.

### Port to Visual Studio:
- Port the project to Visual Studio and make a branch of this repository.

### Collisions & other processor-heavy elements:
- Add method of optimization that only renders and checks collision if an object is in camera view.

# Algorithm:
- Create Screen 
- Create Gameobjects
  - Player
  - Non-Player Entities (NIF)
  - Tiles (NIF) 
  - Items (NIF)
- Start Game Loop
- Updates
- Rendering
- User Input

*NIF = Not Implemented Fully (Has written code but is not yet used at runtime.)




