require 'csv'

total = 0
CSV.foreach('../data/sample.csv') do |row|
  total = total + row[3].to_i
end

print total
