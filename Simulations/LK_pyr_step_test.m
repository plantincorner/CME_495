
clear all
%clc
%% Load Frames
obj = mmreader('test3_sand_slow_60.mp4');
video = obj.read();

%frameStart = 250;
%frameEnd = 270;
h = 5;  %height of camera above groupd
camera_angle_width = 65;  %degrees of viewing angle
number_pixels = 640; %pixels in direction of view angle above
pixel_height = 2*h*tan(camera_angle_width*pi/180/2)/number_pixels;
pixel_height = pixel_height*2;  %2x2 pixel average
scale_factor = 1.2654;  %trial and error to scale velocity

%fstart = [0,20,200,250,305];
%duration = 2;

fstart = 1;
duration = 30;

velComp = zeros(1,duration);
x_velocity = zeros(1,duration);
y_velocity = zeros(1,duration);

%%
for i = 1:length(fstart)
    frameStart = fstart(i);
    frameEnd = frameStart + duration;

Wnew = 280;
Hnew = 280;

x_vel = zeros(1,(frameEnd-frameStart-1));
y_vel = zeros(1,(frameEnd-frameStart-1));
%%
for kk = frameStart:(frameEnd-1)
fprintf('Frame %i to Frame %i...\n', kk, kk+1)
tic;

%video parameters for changing pitch and roll
% F=60;   %frame rate
% if kk<F
%     w_pitch = 30*pi/180;    %rad/sec
%     pitch = 30*(kk)/F*pi/180;
% elseif kk<3*F
%     w_pitch = -30*pi/180;
%     pitch = (30-30*(kk-60)/F)*pi/180;
% else
%     w_pitch = 30*pi/180;
%     pitch = (-30+30*(kk-180)/F)*pi/180;
% end
% Z = 3;
% Vz=0;

%velComp(kk-frameStart+1) = (Vz*tan(pitch)+Z*w_pitch*sec(pitch)^2);


 
        
%convert images to grayscale
I1 = im2double( rgb2gray(video(:,:,:,kk)));
I2 = im2double( rgb2gray(video(:,:,:,kk+1)));
test = I1;

I_height = size(I1,1);
I_width = size(I1,2);

%declare what pixels to keep
I_height_start = (I_height-Hnew)/2;
I_height_end = I_height_start + Hnew;
I_width_start = (I_width-Wnew)/2;
I_width_end = I_width_start + Wnew;

%reduce image size to center square
I1 = I1(I_height_start:I_height_end-1,I_width_start:I_width_end-1);
I2 = I2(I_height_start:I_height_end-1,I_width_start:I_width_end-1);

I1_new = zeros(Hnew/2,Wnew/2);
I2_new = zeros(Hnew/2,Wnew/2);
test2 = I1;
%reduce image by facter of 4
for i = 1:2:size(I1,1)
    for j = 1:2:size(I1,2)
        I1_new((i+1)/2,(j+1)/2) = (I1(i,j)+I1(i+1,j)+I1(i,j+1)+I1(i+1,j+1))/4;
        I2_new((i+1)/2,(j+1)/2) = (I2(i,j)+I2(i+1,j)+I2(i,j+1)+I2(i+1,j+1))/4;
    end
end
I1 = I1_new;
I2 = I2_new;
test3 = I1;

%optic flow. Returns magnitute of flow in the X and Y directions
[flowHor, flowVer] = pyramidFlow(I1, I2, 5, 3, 3);  %pyramidFlow( I1, I2, winSize, ITER_NO, PYRE_NO )

% remove edges. The edges of the optic flow output are noisy 
edge_remove = 20;   %pixels to cut
flowHor = flowHor((edge_remove+1):(length(flowHor(:,1))-edge_remove),(edge_remove+1):(length(flowHor(1,:))-edge_remove));
flowVer = flowVer((edge_remove+1):(length(flowVer(:,1))-edge_remove),(edge_remove+1):(length(flowVer(1,:))-edge_remove));

%take averages
x_vel(kk-frameStart+1) = mean(mean(flowHor));
y_vel(kk-frameStart+1) = mean(mean(flowVer));


fprintf('\tHorizontal = %d\n', x_vel(kk-frameStart+1))
fprintf('\tVertical = %d\n', y_vel(kk-frameStart+1))

t4 = toc;
fprintf('\tRuntime = %f s\n\n',t4);

%calculate velocities
x_velocity(kk-frameStart+1) = x_vel(kk-frameStart+1)*pixel_height*F*scale_factor;
y_velocity(kk-frameStart+1) = y_vel(kk-frameStart+1)*pixel_height*F*scale_factor;

end



%% plot results
F = 60; %frame rate
figure(3)
hold on
plot((frameStart:(frameEnd-1))./F, x_velocity, 'r*')
plot((frameStart:(frameEnd-1))./F, y_velocity, 'b*')
title('Actual and Calculated Velocities','FontSize',16)
xlabel('Time (s)','FontSize',14)
ylabel('Velocity (m/s)','FontSize',14)
hold off




%% reduce histogram
histBins = 100;
threshold = 5;
linArrayFlowVer = zeros(1,size(flowVer,1)*size(flowVer,2));
linArrayFlowHor = zeros(1,size(flowHor,1)*size(flowHor,2));

for i=1:size(flowVer,1)
    for j = 1:(size(flowVer,2))
        
linArrayFlowVer((i-1)*100+j) = flowVer(i,j);
linArrayFlowHor((i-1)*100+j) = flowHor(i,j);

    end
end
figure(90)
hist(linArrayFlowVer,100)
title('Verticle Flow Histogram')

figure(91)
hist(linArrayFlowHor,100)
title('Horizontle Flow Histogram')

end

%%
