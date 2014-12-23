import csv as csv

with open('../data/sample.csv', 'rb') as csvfile:
    reader = csv.reader(csvfile, delimiter = ',')
    total = 0
    for row in reader:
        total = total + int(row[3])
    print total
