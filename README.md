<div align="center">


  <h1>Raycaster</h1>

  <p>
    <b>A first-person SDL2 raycasting experiment inspired by early 3D engines.</b>
  </p>

  <p>
    <img alt="Language C" src="https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white" />
    <img alt="SDL2" src="https://img.shields.io/badge/SDL2-173B6B?style=for-the-badge&logo=libsdl&logoColor=white" />
    <img alt="SDL2 Image" src="https://img.shields.io/badge/SDL2_image-FF6B35?style=for-the-badge&logo=image&logoColor=white" />
    <img alt="Math" src="https://img.shields.io/badge/libm-2E3440?style=for-the-badge&logo=gnu&logoColor=white" />
  </p>

  <p>
    <a href="#features">
      <img alt="Features" src="https://img.shields.io/badge/Features-00C2A8?style=for-the-badge" />
    </a>
    <a href="#build">
      <img alt="Build" src="https://img.shields.io/badge/Build-7C3AED?style=for-the-badge" />
    </a>
    <a href="#controls">
      <img alt="Controls" src="https://img.shields.io/badge/Controls-F59E0B?style=for-the-badge" />
    </a>
    <a href="#demo-video">
      <img alt="Demo video" src="https://img.shields.io/badge/Demo_video-FF3864?style=for-the-badge" />
    </a>
  </p>

</div>

---

## Overview

Raycaster casts one ray per screen column through a fixed `10x10` map, samples a wall texture, applies distance shading, and presents the result as a compact first-person renderer.

The goal is simple: take a flat grid and make it feel like a navigable 3D space using DDA-style traversal, texture slicing, and SDL2 rendering.

## Features

<table>
  <tr>
    <td><b>Ray traversal</b></td>
    <td>DDA-style grid stepping across a fixed <code>10x10</code> map.</td>
  </tr>
  <tr>
    <td><b>Textured walls</b></td>
    <td>One vertical texture slice is rendered per screen column.</td>
  </tr>
  <tr>
    <td><b>Depth shading</b></td>
    <td>Distance-based brightness falloff creates stronger depth cues.</td>
  </tr>
  <tr>
    <td><b>Mouse look</b></td>
    <td>Relative mouse movement rotates the camera.</td>
  </tr>
  <tr>
    <td><b>Collision</b></td>
    <td>Keyboard movement checks the map before moving into a cell.</td>
  </tr>
  <tr>
    <td><b>Focused controls</b></td>
    <td>The cursor is hidden and SDL relative mouse mode is enabled.</td>
  </tr>
</table>

## Tech Stack

<p>
  <img alt="C" src="https://img.shields.io/badge/C-0B5FFF?style=flat-square&logo=c&logoColor=white" />
  <img alt="SDL2" src="https://img.shields.io/badge/SDL2-1F6FEB?style=flat-square&logo=libsdl&logoColor=white" />
  <img alt="SDL2 image" src="https://img.shields.io/badge/SDL2_image-FF7A18?style=flat-square&logo=image&logoColor=white" />
  <img alt="SDL2 ttf headers" src="https://img.shields.io/badge/SDL2_ttf_headers-9B5DE5?style=flat-square" />
  <img alt="libm" src="https://img.shields.io/badge/libm-111827?style=flat-square&logo=gnu&logoColor=white" />
</p>

| Layer | Used for |
| --- | --- |
| `C` | Core loop, movement, raycasting, and rendering logic. |
| `SDL2` | Window, renderer, input events, cursor, and relative mouse mode. |
| `SDL2_image` | Loading the PNG wall texture. |
| `SDL2_ttf` | Included in the SDL header setup for project consistency. |
| `libm` | Trigonometry and distance math. |

## Project Structure

```text
.
|-- main.c        # Raycasting loop, movement, input, texture slicing, rendering
|-- headers.h     # SDL includes and fixed 10x10 map data
|-- backrooms.png # Wall texture
`-- prot          # Existing compiled/development artifact
```

## Build

Install dependencies on Ubuntu/Debian:

```bash
sudo apt install build-essential libsdl2-dev libsdl2-image-dev libsdl2-ttf-dev
```

Compile from the repository root:

```bash
gcc main.c -o raycaster -lSDL2 -lSDL2_image -lSDL2_ttf -lm
```

## Run

```bash
./raycaster
```

Run from the repository root so `backrooms.png` loads correctly.

## Controls

| Input | Action |
| --- | --- |
| Mouse movement | Rotate view |
| Up arrow | Move forward |
| Down arrow | Move backward |
| Left arrow | Strafe left |
| Right arrow | Strafe right |
| Window close | Quit |

## Demo Video

> Demo video placeholder: add the gameplay recording link or embedded media here.


<img width="800" height="450" alt="Raycaster gameplay preview" src="https://github.com/user-attachments/assets/c487f554-c698-46a3-9348-acbf316a85bc" />


## How It Works

The map is a fixed `10x10` integer grid in `headers.h`, where `1` means wall and `0` means walkable space.

For every horizontal pixel column, the renderer:

1. Computes a ray angle from the player angle and field of view.
2. Steps through the grid until the ray hits a wall cell.
3. Calculates the wall hit distance.
4. Chooses the matching texture column.
5. Draws a scaled vertical slice with distance-based brightness.

That combination turns the flat map into a first-person view while keeping the implementation small and readable.

## Current Limitations

| Limitation | Current state |
| --- | --- |
| Map data | Hard-coded in `headers.h`. |
| Debug tools | No minimap or debug overlay yet. |
| Texture projection | Simple texture sampling and distance scaling. |
| Window size | Assumes a `1280x720` render target. |

---

<div align="center">
  <sub>Built with C, SDL2, and ray-column math.</sub>
</div>
