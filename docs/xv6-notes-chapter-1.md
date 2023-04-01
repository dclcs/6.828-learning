## Chapter 1: 操作系统接口

- The job of an operating system is
  - share a computer among multiple programs
  - provide a more useful set of services than the hardware alone supports

- **kernel**: a special program that provides services to run programs.-
**progress**: running program, contain instructions(implement the program's computation), data(variables on which computation acts) and stack(organize the program's procedure calls)
- **system call**: a request from a program to the kernel to perform a service

- the kernel uses the hardware protection mechanisms provided by a CPU to ensure that each process executing in **user space** can access only its own memory. The kernel executes with the hardware privileges required to implement these protections; user programs execute without those privileges. When a user program invokes a system call, the hardware raises the privilege level and starts executing a pre-arranged function in the kernel.

### 1.1 Process and memory

- xv6 process consists of *user-space memory* and *pre-process state private to the kernel*.

- xv6 *time-share* process
  - transparently switches the available CPUs among the set of process's CPU registers, restoring them when it next runs the process.

- **fork**: create a new process
  - gives the new process an exact copy of the calling process's memory, both instructions and data
  - returns in both the original and new processes
    - in the original process, **fork** returns the new process's PID
    - in the new process, **fork** returns zero

- **exit** system call: will causes the calling process to stop executing and to release resources such as memory and open files
  - **exit** takes an integer status argument
    - 0: success
    - 1: failure

- **wait** system call: returns the PID of an exited(or killed) child of the current process and copies the exit status of the child to the address passed to wait;
  - if none of the caller's children has exit, **wait** for one to do so
  - if the caller has no children, **wait** immediately returns -1
  - if the parent doesn't care about the exit status of a child, it can pass a 0 address to **wait**

- **exec* system call: replaces the calling process's memory with a new memory image loaded from a file stored in the file system.
  - the *file* must have a particular format, xv6 uses the ELF format.
  - when **exec** succeeds, it does not return to the calling program;instead, the instructions loaded from the file start executing at the entry point declared in the ELF header.
  - two arguments
    - the name of the file containing the executable
    - an array of string arguments

### 1.2 I/O and File descriptors

- *file descriptor* is a small integer, representing a kernel-managed object that a process may read from or write to.
- *file descriptor* abstracts away the differences between files, pipes and devices, making them all look like streams of bytes.
- xv6 kernels uses the file descriptor as an index into a pre-process table, so that every process has a private space of file descriptors starting at zero.
- 0: standard input; 2: standard error;
- the *read* and *write* system calls read bytes from and write bytes to open files named by *file descriptors*.
  - the *read* reads at most n bytes from the file descriptor fd, copies them into buf, and returns the number of bytes read
  - the *write* writes n bytes from buf to the file descriptor fd and return number of bytes written
  - the *close* system call release a file descriptor, making it free for reuse by a future *open*, *pipe*, or *dup* system call.
- *open*

### 1.3 Pipes

- A *pipe* is a small kernel buffer exposed to processes as a pair of file descriptors, one for reading and one for writing.

### 1.4 File System

- *mkdir* creates a new directory
- *open* with the O_CREATE flag creates a new data file
- *mknod* creates a new device file
- A file's name is distinct from the file itself; the same underlying file, called an *inode*, can have multiple names, called *links*.
  - Each link consists of an entry in a directory; the entry contains a file name and a reference to an inode
  - An inode holds metadata about a file, including its type(file or directory or device), its length, the location of the file's content on the disk, and the number of links to a file
- *fstat* system call retrieves information from the inode that a file descriptor refers to.
