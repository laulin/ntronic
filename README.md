# ntronic

## 🔧 About This Project

Welcome to this open-source educational electronics game designed to help children (and curious adults!) **discover the basics of electricity and electronics through hands-on experimentation**.

The game is made of **modular blocks** that can be easily assembled to create functioning electric circuits — from simple switches to more complex logic and sensor-based modules.

## 🧲 Magnetic Connections

Each module connects to others using **two magnets** and a **metal contact tab**, making assembly intuitive, secure, and fun. There's no need for wires or tools — just snap and play!

## ⚡ Safe and Kid-Friendly

The system runs on **5V**, ensuring **no electrical hazard**. It’s completely safe for supervised educational use and perfect for STEM discovery at home or in the classroom.

## 🧩 Modular System

All blocks follow a **60x60mm base size**, but larger modules can be built using multiples of that base unit. For example, the `power_supply` module is a **1x2 block (60x120mm)** to accommodate additional electronics.

## 🔌 USB-C Power with Built-in Safety

Power is supplied through a dedicated `power_supply` module using **USB-C**. This module also acts as a **circuit breaker**, protecting the system from short circuits and misuse — so you can explore without worry.

# Disclaimer
This project is provided **free of charge** and as **open-source software**, with the primary goal of helping children learn the fundamentals of electricity and electronics.

You are welcome to build, use, and modify this project. However, the following conditions apply:

- **Attribution Requirement**: If you remix, modify, or redistribute this project in any form, you must provide a clear and visible link to this original repository.

- **Commercial Use Prohibited**: Unless you have received explicit written permission from the author, you are strictly prohibited from using any part of this project for commercial purposes. This includes, but is not limited to, selling the code, 3D models, PCBs, kits, or derived products.

- **Safety Notice**: This educational game is not suitable for children under 36 months due to small parts that may pose a choking hazard. Adult supervision by a competent person is required at all times during assembly and use.

This repository contains software code, 3D-printable models, and PCB design files required to build the physical modules.

By using this repository, you acknowledge and agree to comply with these conditions. See LICENCE.txt for more details.

# Quick start guide

## 🛠️ Required Tools and Materials

Before you get started building your own educational electronics kit, make sure you have the following **tools** and **materials** on hand:

### 🧰 Tools

* **3D Printer**
  A 3D printer is required to print the module enclosures. I personally use a **Bambu Lab X1C with AMS** to enable easy color changes for markings.

* **Small Phillips screwdriver**
  Used to install the **metal contact tabs** (battery terminal-style connectors) inside the modules.

* **Soldering iron**
  Needed to insert **brass heat-set inserts** into the printed parts.

* **Hex key for M3 screws**
  Required for assembling the modules with M3 screws.


### 🧱 Materials

* **PETG Filament**
  PETG is recommended for its **durability and resistance to rough handling by children**.

  * I use **gray** for the base parts and **yellow** for the **"tops"** (the removable lids).
  * If your printer doesn’t support multi-color prints, you can **add markings manually** using **paint** or a **permanent marker**.
  * Recommended brand: **Overture PETG**.

* **Brass M3 heat-set inserts**
  Example: [Ruthex M3x5.7 Inserts (Amazon link)](https://www.amazon.fr/dp/B08BCRZZS3)

* **AAA battery-type metal contact tabs**
  Used as connection terminals between modules.
  Example: [AliExpress product link](https://fr.aliexpress.com/item/32946601230.html)

* **M2x6 screws**
  Example: [Amazon link](https://www.amazon.fr/dp/B0CH9ZXMSK)

* **M3x10 screws**
  Example: [Amazon link](https://www.amazon.fr/dp/B0DN79L3NP)

* **20–22 AWG wire**
  Standard insulated wire for connecting components inside the modules.

> 🔧 Additional tools and materials may be required depending on the specific module you're building. These will be listed in each module’s construction guide.


## 📁 Repository Structure

This repository is organized to make it easy for makers to explore, print, and build each module.

### 🧩 `modules/` Directory

This is the core directory containing **all available modules**. Each module has its own subfolder, structured as follows:

```
modules/
├── led/
├── button/
├── power_supply/
├── ...
└── bases/
```

#### 📦 Module folders (`led/`, `button/`, etc.)

Each folder represents a **self-contained module** and includes:

* One or more **STL files** for 3D printing (at minimum, a `top.stl` for the lid)
* **Preview images** (same name as the STL, e.g., `top.png`) for visual reference
* Optionally:

  * A `PCB/` folder with files for the **custom circuit board**
  * A folder for **firmware** or **code** (if the module is programmable)
  * Additional documentation
* A `README.md` explaining the module's purpose, required components, and how to assemble it

#### 🧱 Special folder: `bases/`

This folder contains **base enclosures** used by other modules.
Each module specifies **which base it builds upon** (e.g., 1x1, 1x2…).

Think of it as the physical "shell" shared by multiple modules.

---

This structure ensures modularity and reuse, making it easy to:

* Print only what you need
* Understand how each part fits together
* Extend the project with your own creations

