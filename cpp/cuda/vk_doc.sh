#!/bin/bash

usage='vk-doc keyowrd [lines]'
[ -z $1 ] && return
sudo grep "$1" -A$2 $(grep -P '\.h$' <(sudo find /home/wolf/Downloads/vulkan-sdk/x86_64/include/ -type f)) | less
alias vk-doc='/home/wolf/git/playground/cpp/vulkan/vk_doc.sh'
