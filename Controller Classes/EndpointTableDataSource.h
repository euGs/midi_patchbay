#import <Cocoa/Cocoa.h>
#import <PYMIDI/PYMIDI.h>


@interface EndpointTableDataSource : NSObject {
    Class			endpointClass;
    NSMutableArray*	endpointArray;
    NSUndoManager*  undoManager;
}

- (EndpointTableDataSource*)initWithEndpointClass:(Class)newEndpointClass endpointArray:(NSMutableArray*)newEndpointArray undoManager:(NSUndoManager*)newUndoManager;
- (void)dealloc;

- (void)setEndpointArray:(NSMutableArray*)newEndpointArray;

- (int)numberOfRowsInTableView:(NSTableView*)tableView;
- (id)tableView:(NSTableView*)tableView objectValueForTableColumn:(NSTableColumn*)column row:(int)rowIndex;
- (BOOL)control:(NSControl*)control isValidObject:(id)value;
- (void)tableView:(NSTableView*)tableView setObjectValue:(id)value forTableColumn:(NSTableColumn*)column row:(int)rowIndex;
- (void)deleteSelection:(NSTableView*)tableView;

- (BOOL)tabView:(NSTabView*)tabView shouldSelectTabViewItem:(NSTabViewItem*)tabViewItem;

- (void)tableView:(NSTableView*)tableView newEndpointWithName:(NSString*)name;
- (void)tableView:(NSTableView*)tableView addEndpoint:(PYMIDIVirtualEndpoint*)endpoint atIndex:(int)index;
- (void)tableView:(NSTableView*)tableView removeEndpointAtIndex:(int)index;
- (void)tableView:(NSTableView*)tableView setName:(NSString*)name forEndpointAtIndex:(int)index;

@end
