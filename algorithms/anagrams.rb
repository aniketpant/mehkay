# Generate anagrams

input = 'abc'
anagrams = []

input_length = input.length

words = input.split(' ').length

entry = []
input.each_char { |x|
  entry.push(x) if x != ' '
}

for i in 1..input_length do
  combinations = entry.permutation(i).to_a.map { |x|
    if x.join('').length == 1
      if x.join('') == 'a' or x.join('') == 'i'
        x.join('')
      else
      end
    else
      x.join('')
    end
  }
  anagrams.push(combinations) if combinations.length > 0
end

anagrams = anagrams.flatten.uniq

anagrams.permutation(words).to_a.map { |x|
  if x.all?
    str = x.join(' ')
    puts str if str.length == input_length
  end
}
