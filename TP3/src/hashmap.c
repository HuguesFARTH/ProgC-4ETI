#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct{
  void * key;
  void * value;
} ENTRY;

typedef struct{
  //pas encore utilisé
  int maxSize;
  int size;
  ENTRY *entry;
} HASHMAP;

void printHashMap(HASHMAP* map);
ENTRY getEntryHashMap(HASHMAP *map, int index);
ENTRY getFirstEntryHashMap(HASHMAP *map);
HASHMAP createHashMap();
short containsHashMapKey(HASHMAP* map,void* key);
void* getHashMapValue(HASHMAP* map,void* key);
short increaseSize(HASHMAP* map, int amount);
short putHashMapInc(HASHMAP* map,void* key, void* value, short incrementIfExist);
short putHashMap(HASHMAP* map,void* key, void* value);
short removeHashMap(HASHMAP* map,void* key);

// int main() {
//   printf("Size of ENTRY:%d\n",sizeof(ENTRY));
//   printf("Size of MAP:%d\n",sizeof(HASHMAP));
//   HASHMAP map = createHashMap();
//   printf("bzzz\n");
//   printHashMap(&map);
//   printf("before put\n");
//   printf("put[5,50] :%hd\n", putHashMap(&map,5,50));
//   printHashMap(&map);
//   printf("put[5,50] :%hd\n", putHashMapInc(&map,5,50,1));
//   printHashMap(&map);
//   printf("put[100,50] :%hd\n", putHashMap(&map,100,50));
//   printf("Containskey 100:%hd\n", containsHashMapKey(&map,100));
//   printHashMap(&map);
//   for (int i = 0; map.size; i++) {
//     int k = getFirstEntryHashMap(&map).key;
//     printf("removeHashMap %d:%hd\n", k,removeHashMap(&map,k));
//     printHashMap(&map);
//   }
//   return 0;
// }

void printHashMap(HASHMAP* map){
  printf("Size:%lu\n",(*map).size);
  if((*map).size == 0){
    printf("Empty map\n");
    return;
  }else{
    for(int i = 0; i < (*map).size; i++){
      ENTRY ent = *((*map).entry+i);
      printf("key:%u value:%u\n", ent.key,ent.value);
    }
    return;
  }
}

ENTRY getEntryHashMap(HASHMAP *map, int index){
  if(index < 0 || index > (*map).size){
    return getEntryHashMap(map,(*map).size-1);
  }
  return *((*map).entry+index);
}

ENTRY getFirstEntryHashMap(HASHMAP *map){
  return getEntryHashMap(map,0);
}

HASHMAP createHashMap(){
  // int maxAmount = 2;
  HASHMAP map ;//= malloc(sizeof(ENTRY)+sizeof(int));
  ENTRY *entry;//= malloc(sizeof(ENTRY)*maxAmount);
  // for(int i = 0; i < maxAmount ; i++){
  //   printf("i=%d\n",i);
  //   (entry+i) -> key=(void *)(i+1);
  //   (entry+i) -> value=(void *)((i+1)*(i+1));
  //   ENTRY ent = *(entry+i);
  // }
  map.maxSize = 0;
  map.size = 0;
  map.entry = entry;
  return map;
}

short containsHashMapKey(HASHMAP* map,void* key){
  if((*map).size == 0){
    return 0;
  }else{
    for(int i = 0; i < (*map).size; i++){
      if((*((*map).entry+i)).key == key){
        return 1;
      }
    }
  }
  return 0;
}

void* getHashMapValue(HASHMAP* map,void* key){
  if((*map).size == 0){
    return NULL;
  }else{
    for(int i = 0; i < (*map).size; i++){
      if((*((*map).entry+i)).key == key){
        return (*((*map).entry+i)).value;
      }
    }
  }
  return NULL;
}

short increaseSize(HASHMAP* map, int amount){
  ENTRY *tmp_ptr = malloc(sizeof(ENTRY)*(((*map).size)+amount));
  for(int j = 0; j < (*map).size; j++){
    *(tmp_ptr+j) = *((*map).entry+j);
  }
  (*map).entry = tmp_ptr;
  (*map).size += amount;
  return 1;
}

//refaire la partie incrémentation (bugs)
short putHashMapInc(HASHMAP* map,void* key, void* value, short incrementIfExist){
  // printf("\n");
  // printf("push: %i,%i\n", key,value);
  if((*map).size > 0){
    for(int i = 0; i < (*map).size; i++){
      if((*((*map).entry+i)).key == key){
        if(incrementIfExist){
          (*((*map).entry+i)).value = ((int)(*((*map).entry+i)).value) + ((int)value);
        }else{
          (*((*map).entry+i)).value = value;
        }
        return 1;
      }
    }
  }
  if(increaseSize(map,1)){
    (*((*map).entry+(*map).size-1)).key=key;
    (*((*map).entry+(*map).size-1)).value=value;
    return 1;
  }else{
    printf("Erreur lors de l'agrandissement de la hashmap\n");
  }
  return 0;
}

short putHashMap(HASHMAP* map, void* key, void* value){
  if((*map).size > 0){
    for(int i = 0; i < (*map).size; i++){
      if((*((*map).entry+i)).key == key){
        (*((*map).entry+i)).value = value;
        return 1;
      }
    }
  }
  if(increaseSize(map,1)){
    (*((*map).entry+(*map).size-1)).key=key;
    (*((*map).entry+(*map).size-1)).value=value;
    return 1;
  }else{
    printf("Erreur lors de l'agrandissement de la hashmap\n");
  }
  return 0;
}

short removeHashMap(HASHMAP* map,void* key){
  for(int i = 0; i < (*map).size; i++){
    if((*((*map).entry+i)).key == key){
      ENTRY *tmp_ptr = malloc(sizeof(ENTRY)*((*map).size-1));
      int cpt = 0;
      for(int j = 0; j < (*map).size; j++){
        if(j != i){
          *(tmp_ptr+cpt) = *((*map).entry+j);
          cpt++;
        }
      }
      (*map).entry = tmp_ptr;
      (*map).size -= 1;
      return 1;
    }
  }
  return 0;
}

// Permet d'afficher une hashmap.
// void printHashMap(HASHMAP map){
//   printf("MaxSize:%lu\n",map.maxSize);
//   printf("Size:%lu\n",map.size);
//   if(map.size == 0){
//     printf("Empty map\n");
//   }else{
//     for(int i = 0; i < map.size; i++){
//       ENTRY ent = *(map.entry+i);
//       printf("key:%d value:%d\n", ent.key,ent.value);
//     }
//   }
// }
