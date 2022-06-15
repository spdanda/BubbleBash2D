

# Bubbles Bash 2D





Bubble-Bash is a 2D board game in which player 
has to match 3 or more bubbles to score within 
a limited period of time.

This project is coded in c++ using [SFML Library](https://www.sfml-dev.org/documentation/2.5.1/). 

A Game Engine is designed which can be used again and again for 
developing different kinds of games.


- [Bubbles Bash 2D](#bubbles-bash-2d)
  * [Features](#features)
  * [Installation Required](#installation-required)
  * [Deployment](#deployment)
  * [Different States](#Different-States)
  * [Authors](#authors)
  * [Licenses](#licenses)
  * [Credits](#credits)

## Features

- Reusable Game Engine
- Time Limit Challange
- Easy Interface
- Soothing Background Music

  
## Installation Required 

To run our project, We need to install the
following Items:

 **1.   C++ Compiler (GNU G++)** 
 
 To Install, run the following command in your terminal

```bash
  sudo apt install g++
```

**2. Build System (Make)**

To install, run the following command in your terminal

```bash
sudo apt install make
```
**3. SFML- Simple and Fast Multimedia Library**

To install, run the following command in your terminal

```bash
sudo apt-get install libsfml-dev
```

## Deployment

To compile the project we used *Make(Build system)* .

So to compile, run the following one-worded code 
after changing your working directory to the
project folder :

```bash
  make
```
Now, you can simply use the following code 

```bash
bin/main
```
## Different States


Welcome Screen:


![Splash State]()

Main Menu:


![Main Menu]()

Level State:


![Level]()

Game-Play State:


![Play]()

Help State:


![Help]()

Pause State:


![Pause]()

Game Over state:


![Over]()

## Credits
Used some "free-to-use" music audios and backgroud images.


All the **Music** files are taken from [chosic.com](https://www.chosic.com/) and are registered under *[Creative Commons](https://creativecommons.org/about/cclicenses/)* license.

Links to music used in:

1. [Game Play and Pause State](https://www.chosic.com/download-audio/?t=28349&tag=Guitar)

    Title: Gypsy Doo Wop

    Artist: [John Bartman](https://www.chosic.com/free-music/all/?keyword=John%20Bartmann&artist) 

2. [Menu State,Level State,Help state,etc..](https://www.chosic.com/download-audio/?t=25942&tag=Bright)
   
   Title: Cheer Up!

   Artist: [Keys of Moon](https://www.chosic.com/free-music/all/?keyword=Keys%20of%20Moon&artist)
   
   Attribution as instructed:
   
   Cheer Up! by Keys of Moon | https://soundcloud.com/keysofmoon
   
   Music promoted by https://www.chosic.com
   
   Attribution 4.0 International (CC BY 4.0)
   https://creativecommons.org/licenses/by/4.0/
   


  Following **Backgrounds** are taken from [unsplash.com](https://unsplash.com/) under their [license](https://unsplash.com/license).
    
  1. [Splash Screen](https://unsplash.com/photos/qEswHvOmi1c)
  
  2. [Menu State](https://unsplash.com/photos/p-NQlmGvFC8)
  
  3. [Level State](https://unsplash.com/photos/0YQz7M2fcYY)
   
  4. [Help State](https://unsplash.com/photos/VdFkSO3uePI)
   
  5. [Game-over State](https://unsplash.com/photos/ilfsT5p_qvA)

  For Game-State and Pause state, [background](https://www.behance.net/gallery/46601081/Background-for-mobile-game/modules/278262885) is taken from [behance.net](https://www.behance.net/), under *[Creative commons](https://creativecommons.org/licenses/by-nc-sa/4.0/deed.en_US)* license.

  Artist: [Boris Tovmasyan](https://www.behance.net/rab8bit).
   
Difficulties faced:
Designing the Clock using a struct with all the attributes was a tough job.