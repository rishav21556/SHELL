# Custom Shell README

## Overview

This is a custom shell program written in C language. It provides a command-line interface where users can execute various commands similar to a typical Unix shell.

## Usage

To use the shell, compile the source code and run the executable. Upon execution, the shell prompt will be displayed, indicating that the shell is ready to accept commands.

```bash
make
```

## Supported Commands

The shell supports the following commands:

1. **echo**: Display a line of text. Supports options like `-n` and `-e`.

   Example:
   ```bash
   echo "Hello, World!"
   ```

2. **ls**: List directory contents. Supports options like `-a`, `-A`, and `-t`. The `-t` option runs in a separate thread.

   Examples:
   ```bash
   ls
   ls -a
   ls -A
   ls -t
   ```

3. **cat**: Concatenate and display files. Supports options like `-n` and `-T`. The `-T` option runs in a separate thread.

   Example:
   ```bash
   cat file.txt
   ```

4. **rm**: Remove files or directories. Supports options like `-i` and `-d`. The `-d` option deletes directories. The `-i` option runs in a separate thread.

   Example:
   ```bash
   rm file.txt
   ```

5. **mkdir**: Create directories. Supports options like `-v` and `-p`. The `-p` option creates parent directories if they do not exist. The `-v` option runs in a separate thread.

   Example:
   ```bash
   mkdir new_directory
   ```

6. **date**: Display or set the system date and time. Supports options like `-R` and `-I`. The `-R` option shows the date in RFC 2822 format. The `-I` option shows the date in ISO 8601 format. 

   Example:
   ```bash
   date
   ```

7. **cd**: Change the current directory.

   Example:
   ```bash
   cd /path/to/directory
   ```

8. **pwd**: Print the current working directory. Supports options like `-P` and `-a`. The `-a` option prints additional information about the directory.

   Example:
   ```bash
   pwd
   ```

9. **exit**: Exit the shell.

   Example:
   ```bash
   exit
   ```

## Notes

- The shell supports both built-in commands and external commands available in the system's PATH.
- Threads are used to execute certain commands concurrently for improved performance.
