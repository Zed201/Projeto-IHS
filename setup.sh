#!/bin/bash

GREEN='\033[0;32m'
CLEAR='\033[0m'

echo -e "$GREEN BUILDING APP $CLEAR"
make

echo -e "$GREEN BUILDING DRIVER $CLEAR"
cd driver/pci
make
echo -e "$GREEN REMOVING OLD DRIVERS $CLEAR"
sudo rmmod dei2-150
echo -e "$GREEN INSERTING DRIVER TO KERNEL $CLEAR"
sudo insmod dei2-150.ko
cd ../..

sudo mkdir -p /dev/mydev
echo -e "$GREEN CHANGING DEVICE NODE PERMISSIONS $CLEAR"
sudo chmod 666 /dev/mydev

echo -e "$GREEN DONE! $CLEAR"
echo ""
echo -e "$GREEN IN ORDER TO RUN THE APPLICATION RUN: $CLEAR"
echo -e "$GREEN\t ./app/build/release/app $CLEAR"

