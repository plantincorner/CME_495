theta = -45:0.1:45;%(30+22.52/2);
w = theta.*pi./180;
wAtt = 50;
v = 3*wAtt*pi/180*sec(w).^2; %height*(rad/s)*sec(pitch)^2
avg_v = mean(v(abs(theta)<(10+22.52/2)));

figure(1)
plot(theta,v,'LineWidth',1.5)
hold on
plot([10+22.52/2,10+22.52/2],[min(v) 3.5],'r','LineWidth',1.5)
plot([-10-22.52/2,-10-22.52/2],[min(v) 3.5],'r','LineWidth',1.5)
hold off
title(['Compensation for angular velocity based on attitude angle, with angular velocity = ',num2str(wAtt),' deg/sec'],'FontSize',11)
xlabel('Attitude (deg)','FontSize',10)
ylabel('Apparent Velocity (m/s)','FontSize',10)

%take average over image view
theta2 = -10:0.1:10;
indexStart = 450-100;
indexEnd = 450+100;
extent = 22.52/2;
bound = round(22.52/2/0.1);
new_avg = zeros(1,length(theta2));
for i=1:length(theta2)
    new_avg(i) = mean(v(indexStart-bound+i-1:indexStart+bound+i-1));
end
avg_v2 = mean(new_avg(abs(theta2)<(10)));

figure(1)
hold on
plot(theta2,new_avg,'g','LineWidth',1.5)
%plot([-15 15],[avg_v2 avg_v2],'k')
hold off
legend('Apparent Velocity','FOV, Lower Bound','FOV, Upper Bound','Image Average')

