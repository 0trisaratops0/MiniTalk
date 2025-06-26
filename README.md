# MiniTalk

MiniTalk is a simple inter-process communication project written in C. It uses UNIX signals (`SIGUSR1` and `SIGUSR2`) to transmit a string message from a client process to a server process, bit by bit. The client encodes each character into binary and sends it using signals, while the server decodes and prints the message to standard output.

---

## 🔧 Compilation

To compile the project, run:

```bash
make
```

This will produce two executables:

- `server`  
- `client`

---

## ▶️ Usage

### 1. Start the Server

In one terminal window, run:

```bash
./server
```

It will print its PID (process ID). Example:

```
12345
```

### 2. Send a Message with the Client

In a separate terminal, run the client with the server’s PID and the message:

```bash
./client 12345 "Hello, MiniTalk!"
```

The server will then display:

```
Hello, MiniTalk!
```

Each character is transmitted using 8 signals (one per bit), with `SIGUSR1` representing `1` and `SIGUSR2` representing `0`. A short pause (`usleep`) is added between signals to ensure reliable transmission.

---
