%% adventofcode.com/2019/day/3
%% Alberto Santagostino

close all
clear variables
clc

function manhattan_distance = compute_manhattan_distance(point)
    manhattan_distance = abs(point(1)) + abs(point(2));
end

function [origin, line_coords, overall_steps] = create_path(origin, direction, steps, line_coords, overall_steps)
    x = origin(2);
    y = origin(1);

    switch direction
        case 'L'
            line_coords = [line_coords; [flipud([y * ones(1, steps + 1); x - steps:x]') [overall_steps:1:overall_steps+steps]']];
            new_x = x - steps;
            new_y = y;
        case 'R'
            line_coords = [line_coords; [[y * ones(1, steps + 1); x:x + steps]' [overall_steps:1:overall_steps+steps]']];
            new_x = x + steps;
            new_y = y;
        case 'D'
            line_coords = [line_coords; [[y:y + steps; x * ones(1, steps + 1)]' [overall_steps:1:overall_steps+steps]']];
            new_x = x;
            new_y = y + steps;
        case 'U'
            line_coords = [line_coords; [flipud([y - steps:y; x * ones(1, steps + 1)]') [overall_steps:1:overall_steps+steps]']];
            new_x = x;
            new_y = y - steps;
    end
    overall_steps = overall_steps + steps;
    origin(2) = new_x;
    origin(1) = new_y;
end

function [line_coords] = process_line(l, origin)
    wire_path = strsplit(l, ',');
    line_coords = [];
    overall_steps = 0;
    for n = 1:length(wire_path)
        tk = wire_path(n);
        direction = tk{1}(1);
        steps = str2num(tk{1}(2:end));
        [origin, line_coords, overall_steps] = create_path(origin, direction, steps, line_coords, overall_steps);
        line_coords(end,:) = [];
    end
end

fid = fopen("input.txt");
line1 = fgetl(fid);
line2 = fgetl(fid);
fclose(fid);

line1_coords = process_line(line1, [0 0]);
line2_coords = process_line(line2, [0 0]);

common_coords = intersect(line1_coords(:,1:2), line2_coords(:,1:2), 'rows');
common_indices_1 = find(ismember(line1_coords(:,1:2),common_coords,'rows'));
common_indices_2 = find(ismember(line2_coords(:,1:2),common_coords,'rows'));

line1_coords = sortrows(line1_coords(common_indices_1,:),[1 2]);
line2_coords = sortrows(line2_coords(common_indices_2,:),[1 2]);

line1_coords((line1_coords(:, 1)==0)&(line1_coords(:, 2)==0),:) = [];
line2_coords((line2_coords(:, 1)==0)&(line2_coords(:, 2)==0),:) = [];

nearest_d = inf;

for n = 1:length(common_coords)
    if ~all(common_coords(n, :) == [0 0])
        d = compute_manhattan_distance(common_coords(n, :));
        if d < nearest_d
            nearest_d = d;
        end
    end
end

min_path_sum = inf;
min_path_index = -1;

for n = 1:length(common_coords)-1
    path_sum = line1_coords(n,3) + line2_coords(n,3);
    if(path_sum < min_path_sum)
        min_path_sum = path_sum;
        min_path_index = n;
    end
end

fprintf('Solution (part 1): %d\n', nearest_d);
fprintf('Solution (part 2): %d\n', min_path_sum);
