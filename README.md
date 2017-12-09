# Raspberry-Pi-Studio-Daemon
The daemon of studio on Raspberry Pi

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
cmake .
make
```

# Usage

Raspberry Pi Studio Daemon automatically become daemon allway.
Forexample You run this on terminal or call by init.
