# 🎮 Raycasting Engine (C + SDL2)

> A real-time 2.5D raycasting engine built from scratch in C using SDL2, implementing DDA-based wall detection and texture-mapped rendering.

---

## 🚀 Overview

This project is a custom-built raycasting engine that simulates a 3D environment from a 2D grid map using classic rendering techniques.

It demonstrates how early 3D engines (like *Wolfenstein 3D*) generated immersive environments using:

* raycasting
* grid traversal (DDA)
* perspective projection
* texture sampling

The engine renders walls column-by-column in real time based on the player’s position and viewing angle.

---

## ✨ Features

* 🧭 First-person camera system
* 🧱 Grid-based world (2D map → 3D projection)
* 📡 Raycasting per screen column
* 📐 DDA (Digital Differential Analyzer) algorithm for wall detection
* 🎨 Texture-mapped walls
* 🌗 Distance-based lighting (shading)
* 🎮 Player movement with collision detection
* 🖱️ Mouse-controlled camera rotation (relative mode)

---

## 🛠️ Tech Stack

* **Language:** C
* **Libraries:**

  * SDL2
  * SDL2_image
* **Core Concepts:**

  * Raycasting
  * DDA grid traversal
  * Trigonometry (sin/cos for direction vectors)
  * Perspective projection
  * Texture sampling
  * Real-time rendering loops

---

## 🧠 How It Works

### 1. Raycasting

For each vertical screen column:

* A ray is cast from the player’s position
* Angle is computed based on field of view (FOV)
* Direction vector is derived using `cos` and `sin`

---

### 2. DDA Algorithm

The engine steps through the grid efficiently:

* Computes:

  * `deltaDistX`, `deltaDistY`
  * `sideDistX`, `sideDistY`
* Advances cell-by-cell until a wall is hit
* Determines whether collision occurred on:

  * X-side (vertical wall)
  * Y-side (horizontal wall)

---

### 3. Distance & Projection

* Distance to wall is computed
* Wall height is calculated using perspective:

```id="p4m8mk"
height = screen_height / distance
```

* This creates the illusion of depth

---

### 4. Texture Mapping

* Wall hit position determines texture coordinate (`wallX`)
* A vertical slice of the texture is sampled and drawn
* Each column renders a 1-pixel wide textured strip

---

### 5. Lighting

* Brightness decreases with distance:

```id="q9n1yt"
brightness = 1 / (1 + distance²)
```

* Creates depth perception and realism

---

## 🎮 Controls

| Key   | Action        |
| ----- | ------------- |
| ↑     | Move forward  |
| ↓     | Move backward |
| ←     | Strafe left   |
| →     | Strafe right  |
| Mouse | Look around   |

---

## 🗺️ Map System

* 2D grid (10x10)
* `1` = wall
* `0` = empty space

```id="h7d2qs"
int damap[10][10] = { ... };
```

---

## 📁 Project Structure

```id="g5m2xr"
project/
├── main.c            # Raycasting engine + game loop
├── headers.h         # Shared utilities (if any)
├── assets/
│   ├── backrooms.png
│   ├── car.png
│   ├── wh.png
│   ├── whl.png
│   ├── whr.png
├── README.md
```

---

## ⚙️ Build Instructions

### Linux

```bash id="c3v8pl"
gcc main.c -o raycaster -lSDL2 -lSDL2_image -lm
```

---

## ▶️ Run

```bash id="y8k2fn"
./raycaster
```

---

## 📸 Demo

*Add GIF showing movement and rendering*

---

## 🎯 Purpose

games are a big part of my life , and i always wondered how games like doom were able to use the 3d graphics so early ,
thats when i learned abt raycasting , depth ,dda and the whole 2.5d concept, this was an application of what i learned

---

## 🧠 What I Learned

at first i was using a naive pixel by pixel advancing dot (ray) system , then i learned dda , and boy the difference i saw in the 
texture , the clarity and the depth was very noticeable , it was worth the time of learning it

---

## 🚧 Status

* Raycasting engine: ✅
* DDA traversal: ✅
* Texture mapping: ✅
* Player movement: ✅
* Lighting: ✅
* Advanced features: ⏳(could com later to change it into a full game 
---




---

## 🤝 Contributing

Contributions are welcome. Feel free to open issues or submit pull requests.

---

## 📄 License

no license
