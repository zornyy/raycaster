# Raycaster software renderer

- ⚡ Old school software renderer
- 🔫 Raycasting rendering
- ✝️ Written purely in C just as god intended


## Table of content 🗃️
- **[Introduction 💡](#introduction-💡)**
- **[Technical specifications 📂](#technical-specifications-📂)**
- **[Download & Use ✅](#download--use-✅)**
- **[Build & Code 👩‍🏭](#build--code-👩‍🏭)**
- **[Links 🔗](#links-🔗)**

## Introduction 💡
This repository is a personal project which I started because I wanted to improve my C programmign abilities. At first the aim is to get a working projection of the world, move and explore it. Note that the project has no fixed end and that I will try to make it evolve by adding different features like texturing, adding weapons and making it a small game.

## Technical specifications 📂
### Phase 1
- Working movement
- Player collision
- Projection of the environement

### Phase 2
 - Surfaces texturing
 - Sprites objects

### Phase 3
- Interactions
- Weapons
- Enemies
- Shooting ability

### Phase 4
- Lightning
- Level editor
- Complex levels (stairs, moving heights, doors etc. etc.)

## Download & Use ✅
**No releases yet, you can still download the source code and build it for yourself [here](#build--code-👩‍🏭)**

## Build & Code 👩‍🏭
The project is developed on linux. It uses the SDL2 library with C as a programming language.

```shell
# To clone and try the project

# Build for debian based Linux
# Only the package manager changes for other distros

# just in case
sudo apt install git
sudo apt install gcc
sudo apt install make

# download dependencies & project
sudo apt install libsdl2-dev
sudo apt install libsdl2-ttf-dev
git clone https://github.com/zornyy/raycaster.git
cd raycaster

# compile & run
make
./raycaster
```

## Links 🔗
`Nothing here yet`