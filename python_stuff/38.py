import random
import string

VOWELS="aeiouäëyöü"
CONSONANTS="mpbfvntdsžrlšźkgxjẑ"

for i in range(len(CONSONANTS)):
    i = i + 1
    for j in range(len(VOWELS)):
        print(CONSONANTS[i]+VOWELS[j])
        j = j + 1