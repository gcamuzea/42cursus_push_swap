#!/bin/bash

vogsphere_folder="~/cursus42/push_swap";
git_folder="~/cursus42/repos_git/42cursus_push_swap";

if [ !$1 ]
then
    echo "script needs an argument for commit message";
else
    cd ../../push_swap
    pwd
    git add .
    git commit -m "$1"
    git push
    cd ../repos_git/42cursus_push_swap
    cp -r ../../push_swap/* .
    git add .
    git commit -m "$1"
    git push
fi