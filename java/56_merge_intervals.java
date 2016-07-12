/**
 * Definition for an interval.
 * public class Interval {
 *     int start;
 *     int end;
 *     Interval() { start = 0; end = 0; }
 *     Interval(int s, int e) { start = s; end = e; }
 * }
 */
public class Solution {
    public List<Interval> merge(List<Interval> intervals) {
        //List<Interval> mergedIntervals = new ArrayList<Interval>();
        
        List<Interval> finalMergedIntervals = new ArrayList<Interval>();
        
        
        //pre-sort the intervals
        TreeSet<Interval> sortedIntervals = new TreeSet<Interval>(new MyComp());
        
        for(Interval interval : intervals)
        {
            sortedIntervals.add(interval);
        }
        
        TreeSet<Interval> intermediateMergedIntervals = new TreeSet<Interval>(new MyComp());
        
        //iterate over the sorted intervals
        //can we merge an interval with existing one in the set
        // in one pass
        //rather than compare with all
        //just compare with smaller set and work up..
        //ideally want to insert into set 
        // where is should merge
        
        //as in set order
        // if predecessor doesn't merge and I don't merge
        // then move predecessor to veryfinalset
        /*for(Interval interval : sortedIntervals)
        {
            mergedIntervals.add(interval);
        }*/
        
        Boolean firstTime = true;
        
        while(true)
        {
            Boolean mergesDone = false;
            //for(int i=0; i< mergedIntervals.size() ; ++i)
            Iterator current = sortedIntervals.iterator();
            Iterator next = sortedIntervals.iterator();
            
            if(next.hasNext())
            {
                next.next(); //so one ahead of current
            }
            
            if(firstTime)
            {
                mergesDone = true;
                firstTime = false;
            }
            
            while(current.hasNext())
            {
                //Interval first = mergedIntervals.get(i);
                Interval first = (Interval) current.next();
                
                //if(i+1 < mergedIntervals.size())
                if(next.hasNext())
                {
                    
                    Interval second = (Interval) next.next();
                    
                    Boolean merged = false;
    
                    if( doesFirstOverlapSecond(first,second) || 
                        doesFirstOverlapSecond(second,first))
                    {
                       //System.out.println(getInterval(first) + " overlaps " + getInterval(second));
                        Interval imerged = mergeIntervals(first,second);
                        //finalMergedIntervals.add(imerged);
                        intermediateMergedIntervals.add(imerged);
                        merged = true;
                        mergesDone = true;
                        //i++; //to skip merge already done
                        if(current.hasNext())
                        {
                            current.next();
                            if(next.hasNext())
                            {
                                next.next();
                            }
                        }
                    }
                    
                    
                    
                    if(!merged)
                    {
                        //System.out.println(getInterval(first) + " doesn't overlap " + getInterval(second));
                        
                        //if(mergesDone)
                        //{
                            intermediateMergedIntervals.add(first);
                        //}
                        //else
                        //{
                        //    finalMergedIntervals.add(first);
                        //}
                        //intermediateMergedIntervals.add(first);
                        
                        /*if(i+1==mergedIntervals.size()-1)
                        {
                           finalMergedIntervals.add(second); 
                        }*/
                    }
                }
                else
                {
                    //last value
                   // System.out.println(getInterval(first) + "saved");
                    //finalMergedIntervals.add(first);
                    intermediateMergedIntervals.add(first);
                }
            }
            
            /*if(finalMergedIntervals.size()==0 && mergedIntervals.size()==1 )
            {
                finalMergedIntervals.add(mergedIntervals.get(0));
            }*/
            
            /*if(finalMergedIntervals.size()==0 && sortedIntervals.size()==1 )
            {
                finalMergedIntervals.add((Interval) sortedIntervals.iterator().next());
            }*/
            
            if(mergesDone)
            {
                //mergedIntervals.clear();
                sortedIntervals.clear();
                for(Interval interval : intermediateMergedIntervals)
                {
                    //mergedIntervals.add(interval);
                    sortedIntervals.add(interval);
                }
                
                //finalMergedIntervals.clear();
                intermediateMergedIntervals.clear();
            }
            else
            {
                /*if(intermediateMergedIntervals.size()==1)
                {
                   finalMergedIntervals.add((Interval) intermediateMergedIntervals.iterator().next());
                }*/
                for(Interval interval : intermediateMergedIntervals)
                {
                    //mergedIntervals.add(interval);
                    finalMergedIntervals.add(interval);
                }
                break;
            }
        }
        
        return finalMergedIntervals;
    }
    
    String getInterval(Interval interval)
    {
        String out = interval.start + "," + interval.end;
        return out;
    }
    
    Boolean doesFirstOverlapSecond(Interval first, Interval second)
    {
        Boolean overlap = false;
        
        // first   1,3
        // second  2,6

        // first    1,6
        // second   2,3
        
        if(first.start <= second.start &&
           first.end >= second.start   )
        {
           overlap = true;
        }
        
        return overlap;
    }
    
    Interval mergeIntervals(Interval first, Interval second)
    {
        Interval merged = new Interval();
        
        merged.start = first.start < second.start ? first.start : second.start;
        merged.end = first.end > second.end ? first.end : second.end;
        
        return merged;
    }
    
    class MyComp implements Comparator<Interval>
    {
        public int compare(Interval first, Interval second)
        {
            if( first.start >= second.start & first.end >= second.end)
            {
                    //works for [1,5] vs [2,3]
                    // but for [1,5] vs [2,4] vs [2,3]? may get relative order wrong ?
                return 1;
            }
            else
            {
                return -1;
            }
        }
    }
}