package main

import (
	"encoding/csv"
	"fmt"
	"io"
	"os"
	"strconv"
)

func main() {
	file, err := os.Open("../data/sample.csv")
	if err != nil {
		fmt.Println("Error:", err)
		return
	}

	reader := csv.NewReader(file)

	reader.Comma = ','
	lineCount := 0
	total := int64(0)
	for {
		record, err := reader.Read()

		if err == io.EOF {
			// fmt.Println("Error:", err)
			break
		}

		// fmt.Println("Record:", lineCount, "is", record, "and has", len(record), "fields")

		num, _ := strconv.ParseInt(record[3], 0, 64)
		total = total + num
		// for i := 0; i < len(record); i++ {
		// fmt.Println(" ", record[i])
		// }
		lineCount += 1
	}
	fmt.Println(" ", total)
}
