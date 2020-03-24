# How to get started with the code

Disclaimer: This isn't the best way to do it, just the way I'd reccommend. 

The most straightforward way is to install either ubuntu on a VM / real PC, or 
Ubuntu with WSL. 

After that, you need a compiler, gcc will do, and it's what we're using in 
class I guess. 

## Ubuntu (Actual Linux)
Download an install disc from here: 

https://ubuntu.com/download/desktop

18.04 should have the best support, 16.04 is also fine, if you want to use a 
different distro then you than you probably don't need to be reading this 
guide. 

Burn that onto an actual DVD or use that when you're setting up VMWare Player 
15 (it's in the first window, choose "Installer disc image file").

## Ubuntu WSL (The easy way on windows)

If you're on windows and don't want to bother with trying to get gcc to work 
on windows, just use WSL, it basically gives you a Ubuntu VM, but without the 
graphics stuff, you can only use the command line.

Instructions ripped from https://docs.microsoft.com/en-us/windows/wsl/install-win10

1. Open Powershell as Administrator: 
Right click the start button, choose "Windows Powershell (Admin)"

2. Run this command:

    Enable-WindowsOptionalFeature -Online -FeatureName Microsoft-Windows-Subsystem-Linux

After this you MUST restart your PC. 

3. Go to the Windows Store (ew) and find your favourite linux distro (Ubuntu 
18.04 works fine). Install it. I think it's self-evident from there.

## Getting GCC

Most distros come with a compiler of some kind, but you can get a quick set of 
(probably) everything we need with 3 packages:

1. Open a terminal on your linux distro.

2. Install GCC with:

    sudo apt install build-essentials

It'll probably ask you to say yes, say yes. You need internet. If you're not 
using ubuntu or WSL, you probably already know how to do this on your own 
distro.

3. You can check with GCC is installed with

    gcc --version