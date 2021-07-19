from sys import argv
from cs50 import get_string

if len(argv) != 3:# if lengh is not correct then exit
    print('Error')
    exit(1)

csv_file = open(argv[1], 'r') #opening and reading csv files everything 'r'

strands = [] #defines list
persons = {} #defining open dictionary

for ind, row in enumerate(csv_file): #adds a counter of the csv file
    if ind == 0:
        strands = [strand for strand in row.strip().split(',')][1:] #scans each strand reading  STRs

    else:
        curr_row = row.strip().split(',')
        persons[curr_row[0]] = [int(x) for x in curr_row[1:]] #defines the window as 4

dna_strand = open(argv[2], 'r').read()

final_strands = [] #defining list to be filled

for strand in strands:
    i = 0
    max_strand = -1
    cur_max = 0
    while i < len(dna_strand):
        cur_window = dna_strand[i: i + len(strand)]

        if cur_window == strand:
            cur_max += 1 #moves it over by 1
            max_strand = max(max_strand, cur_max)
            i += len(strand)

        else:
            cur_max = 0
            i += 1

    final_strands.append(max_strand)

for name,data in persons.items():
    if data == final_strands:
        print(name)
        exit(0)

print('No match')