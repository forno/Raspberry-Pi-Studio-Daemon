# Raspberry-Pi-Studio-Daemon
The daemon of studio on Raspberry Pi

# System structure
## Algorithm

1. Observe light of room.
2. If turn the light level then notify open/closed status.

## Electronic circuit

Connect light sensor to the wiring pin 0 (Pin 11, GPIO 17 on RP3).

# Build

1. Download Raspberry-Pi-Studio-Daemon. ex) `git clone https://github.com/CIR-KIT/Raspberry-Pi-Studio-Daemon.git`
2. Change working directory to project top. ex) `cd Raspberry-Pi-Studio-Daemon`
3. Access to LINE Notify. [Here is LINE Notify.](https://notify-bot.line.me/my/)
4. Create Access token for the channel what is notify target.
5. Put access token to `src/token` with double quote wrap. like `"<token>"`.
6. Build by CMake. ex) `cmake .; make`

## Work example

```bash
git clone https://github.com/CIR-KIT/Raspberry-Pi-Studio-Daemon.git
cd Raspberry-Pi-Studio-Daemon
# Get Access token
echo '"<token>"' > src/token
mkdir build && cd build
cmake ..
make
```

# Usage
## Register automatically launch

Run after build.

```bash
cd Raspberry-Pi-Studio-Daemon/build
sudo make install
```

## Manualy launch
Raspberry Pi Studio Daemon automatically become daemon allway.
Forexample You run this on terminal or call by init.

Note: The program require super user permittion for Wiring Pi.

```bash
sudo build/studio_daemon
```
