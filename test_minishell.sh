#!/bin/bash

# Couleurs pour lisibilité
RED="\033[31m"
GREEN="\033[32m"
YELLOW="\033[33m"
RESET="\033[0m"

MINISHELL=./minishell

# Vérifie si minishell est compilé
if [ ! -f "$MINISHELL" ]; then
  echo -e "${RED}❌ Minishell n'est pas compilé. Lance 'make' d'abord.${RESET}"
  exit 1
fi

echo -e "${YELLOW}🚀 Lancement des tests de parsing...${RESET}"
echo

# Tableau de tests : "commande attendu"
declare -a tests=(
  'echo hello world'
  'echo "bonjour $USER dans $HOME"'
  'echo coucou | cat -e'
  'ls -l > outfile.txt'
  'grep "t" < infile.txt | sort | uniq >> results.txt'
  'echo "text with unmatched quote'
  'echo << file | cat >> file2'
  '| echo start'
  'echo end |'
)

for cmd in "${tests[@]}"; do
  echo -e "${YELLOW}Commande :${RESET} $cmd"
  echo "$cmd" | $MINISHELL
  echo -e "----------------------------------\n"
done

echo -e "${GREEN}✅ Tests terminés.${RESET}"