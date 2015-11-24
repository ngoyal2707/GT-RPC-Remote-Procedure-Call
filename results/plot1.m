cache_size = [64,128,192]

% random load response_no_cache=[864088,864088,864088]
response_random=[495440,428689, 382818]
response_LRU=[570100, 425000, 330654]
response_LFU=[569808, 508257, 483281]
response_no_cache=[864088,864088,864088]

% repeated load
response_random =[457968, 146610, 150257]
response_LRU =[ 506079,122029 , 138340]
response_LFU =[ 355257,317668,268472 ]
response_no_cache=[655588,655588,655588]

hitrate_random=[0.54, 0.81,0.833]
hitrate_LRU=[0.50,0.83,0.83]
hitrate_LFU=[0.62,0.70,0.74]
plot(cache_size, hitrate_random, 'b-o', cache_size, hitrate_LFU, 'g-*' ,cache_size, hitrate_LRU, 'r-+' )
% plot(cache_size, response_random, 'b-o', cache_size, response_LFU, 'g-*' ,cache_size, response_LRU, 'r-+' , cache_size,response_no_cache, 'm-s' )
grid on
grid minor
xlabel('cache size (in KB)')
ylabel('Hit Ratio')
%ylabel('Average response time (in microsecond)')
title('Repeated workload')
legend('Random cache policy','LFU policy','LRU policy','No cache policy')
grid minor
ax = gca
ax.XTick=[64,128,192]