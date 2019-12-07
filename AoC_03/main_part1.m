%% adventofcode.com/2019/day/3
%% Alberto Santagostino

close all
clear variables
clc

function manhattan_distance = compute_manhattan_distance(point)
    manhattan_distance = abs(point(1)) + abs(point(2));
end

function [origin, line_coords] = create_path(origin, direction, steps, line_coords)
    x = origin(2);
    y = origin(1);
    switch direction
        case 'L'
            line_coords = [line_coords; [y * ones(1, steps + 1); x - steps:x]'];
            new_x = x - steps;
            new_y = y;
        case 'R'
            line_coords = [line_coords; [y * ones(1, steps + 1); x:x + steps]'];
            new_x = x + steps;
            new_y = y;
        case 'D'
            line_coords = [line_coords; [y:y + steps; x * ones(1, steps + 1)]'];
            new_y = y + steps;
            new_x = x;
        case 'U'
            line_coords = [line_coords; [y - steps:y; x * ones(1, steps + 1)]'];
            new_y = y - steps;
            new_x = x;
    end
    origin(2) = new_x;
    origin(1) = new_y;
end

function [line_coords] = process_line(l, origin)
    wire_path = strsplit(l, ',');
    line_coords = [];
    for n = 1:length(wire_path)
        tk = wire_path(n);
        direction = tk{1}(1);
        steps = str2num(tk{1}(2:end));
        [origin, line_coords] = create_path(origin, direction, steps, line_coords);
    end
end

fid = fopen("input.txt");
line1 = fgetl(fid);
line2 = fgetl(fid);
fclose(fid);

line1_coords = process_line(line1, [0 0]);
line2_coords = process_line(line2, [0 0]);

common_coords = intersect(line1_coords, line2_coords, 'rows');

nearest_d = inf;

for n = 1:length(common_coords)
    if ~all(common_coords(n, :) == [0 0])
        d = compute_manhattan_distance(common_coords(n, :));
        if d < nearest_d
            nearest_d = d;
        end
    end
end

fprintf('Solution (part 1): %d\n', nearest_d);
