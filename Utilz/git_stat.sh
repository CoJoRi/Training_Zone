#!/bin/bash

# Répertoire de base
BASE_DIR="."

# Couleurs ANSI
GREEN="\033[0;32m"
RED="\033[0;31m"
BLUE="\033[0;34m"
NC="\033[0m" # Pas de couleur

# Fonction pour vérifier le statut Git
check_git_status() {
    if [ -d "$1/.git" ]; then
        cd "$1"
        STATUS=$(git status --porcelain)
        echo "----- Repository: $1 -----"
        if [ -z "$STATUS" ]; then
            echo -e "${GREEN}Up-to-date${NC}"
        else
            echo -e "${RED}Changes to commit or untracked files:${NC}"
            git status
        fi
        echo
        cd - > /dev/null
    else
        echo -e "${BLUE}No Git repository in: $1${NC}"
        echo
    fi
}

# Parcourir tous les sous-dossiers
for dir in "$BASE_DIR"/*; do
    echo "Checking directory: $dir"
    if [ -d "$dir" ]; then
        check_git_status "$dir"
    fi
done
