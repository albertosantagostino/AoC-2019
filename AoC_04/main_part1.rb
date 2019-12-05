# !/usr/bin/env ruby

# Alberto Santagostino
# https://adventofcode.com/2019/day/4 (part 1)

def check_adjacent_digits(x)
  digit = x % 10
  x = x / 10
  while x > 0
    if digit == x % 10
      return true
    end
    digit = x % 10
    x = x / 10
  end
  return false
end

def check_increasing_digits(x)
  digit = x % 10
  x = x / 10
  while x > 0
    if digit < x % 10
      return false
    end
    digit = x % 10
    x = x / 10
  end
  return true
end

passwords = 0
x = ARGV[0].to_i
x_end = ARGV[1].to_i

puts "Searching for passwords in [#{x},#{x_end}]"
while x <= x_end
  if check_adjacent_digits(x) && check_increasing_digits(x)
    passwords = passwords + 1
    puts "Find one! #{x}"
  end
  x = x + 1
end
puts "Solution (part 1): #{passwords}"
