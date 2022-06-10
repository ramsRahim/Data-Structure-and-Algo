class hash_map:
    def __init__(self):
        self.MAX = 100
        self.arr = [None for i in range(self.MAX)]

    def get_hash(self,key):
        h=0
        for char in key:
            h += ord(char)
        return h%self.MAX

    def __setitem__(self,key,val):
        h = self.get_hash(key)
        self.arr[h] = val

    def __getitem__(self,key):
        h = self.get_hash(key)
        return self.arr[h]

    def __delitem__(self,key):
        h = self.get_hash(key)
        self.arr[h]=None


    
if __name__ == '__main__':
    t = hash_map()
    t['rahim']=50
    t['hossain']=52
    del t['rahim']
    print(t['rahim'])
