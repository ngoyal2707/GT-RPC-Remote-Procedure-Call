#include "PageCache.h"
#include <iostream>
#include <cstdlib>
#include <limits>

bool PageCache::getPage(const string &url, WebPage &webpage){
	std::tr1::unordered_map<string, ListNode *>::const_iterator it = this->hashMap.find(url);
	if(it!=this->hashMap.end()){ 
		ListNode * node = it->second;
		node->frequency += 1;
		this->hashMap[node->url] = node;
		webpage = node->webpage;
		return true;
	}
	else{
		return false;
	}
}

string getLFUKey(std::tr1::unordered_map<string, ListNode *> &hashMap){
    string key = "";
    int minFreq = std::numeric_limits<int>::max();;
		std::tr1::unordered_map<string, ListNode *>::const_iterator it = hashMap.begin();	
		while(it!=hashMap.end()){
			ListNode *node = it->second;
			if (minFreq > node->frequency){
				key = node->url;
				minFreq = node->frequency;
			}
			it++;
		}
    return key;
}

void PageCache::putPage(const string &url, WebPage &webpage){
	// Page is too big to hold in cache
	if(webpage.len > MAX_SIZE){
		return;
	}
	queueSize += webpage.len; 
	queueEntries++;

	if (queueSize > MAX_SIZE){
		while(queueSize > MAX_SIZE){ // exclude some entries
			cout<<"Size exceeded, removing the LFU entry\n";
			string keyToBeRemoved = getLFUKey(this->hashMap);
			queueSize -= (this->hashMap[keyToBeRemoved]->webpage).len;
			queueEntries--;
      this->hashMap.erase(keyToBeRemoved);
			if(queueSize <= MAX_SIZE){ 
		  	ListNode *node = new ListNode();
				node->url = url;
				node->webpage = webpage;
				node->frequency = 1;
				this->hashMap[node->url] = node; 
			}
  	}
	}
	else{
		ListNode *node = new ListNode();
		node->url = url;
		node->webpage = webpage;
		node->frequency = 1;
		this->hashMap[node->url] = node;		
	}
}
