#!/bin/bash

starting_path=$PWD;
vogsphere_folder="/mnt/nfs/homes/gucamuze/cursus42/push_swap";
git_folder="/mnt/nfs/homes/gucamuze/cursus42/repos_git/42cursus_push_swap";

echo "$1";

if [ $# -eq 0 ]
then
    echo "script needs an argument for commit message";
else
    cd $vogsphere_folder
    pwd
    git add .
    git commit -m "$1"
    git push
    cd $git_folder
    cp -r $vogsphere_folder/* $git_folder
    git add .
    git commit -m "$1"
    git push
    cd $starting_path;
fi