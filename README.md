# game
# linux game

# 🎮 MyWebApp — Web Game&app Launcher for Debian but ofline

> A simple Qt application that runs your web-based game as a desktop app on Debian systems.

This launcher starts an internal HTTP server and loads your game from the `web/` folder, so you can play it without opening a browser.

---

## 📦 What's Included

- `MyWebApp` — The executable file
- `web/` — Folder containing all your game files (`index.html`, `.wasm`, `.json`, `.ogg`, etc.)

---

## ⚙️ Requirements

Before running, install these packages on any Debian-based system:
# install frome git
```bash
sudo apt install git
```
```bash
git clone https://github.com/linuxtopG/game.git
```
```bash
cd game
```
## if you have app game or any html&css&js you can convertet to cpp app jast past all fiels in web dir game/web
## to convert 
```bash
cd game
```
```bash
mkdir build
cd build
cmake ..
make
```
```bash
./MyWebApp
```

```bash
sudo apt update
sudo apt install qtbase5-dev qtchooser qtwebengine5-dev python3
```




