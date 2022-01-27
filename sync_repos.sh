#!/bin/bash

vogsphere_folder="../../push_swap";
git_folder="../repos_git/42cursus_push_swap";

if [ !$1 ]
then
    echo "script needs an argument for commit message";
else
    cd $vogsphere_folder
    pwd
    git add .
    git commit -m "$1"
    git push
    cd $git_folder
    cp -r $vogsphere_folder/* .
    git add .
    git commit -m "$1"
    git push
fi