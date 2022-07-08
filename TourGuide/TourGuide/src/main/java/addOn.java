/*
    This is the decorator class that adds things to the tours
*/

public abstract class addOn implements Tour {

    protected Tour tempTour;
     
    public addOn (Tour newTour)
    {
        tempTour = newTour;
    }
     
    @Override
    public String getDescription()
    {
        return tempTour.getDescription();
    }
    @Override
    public double getCost()
    {
        return tempTour.getCost();
    } 
    @Override
    public int getMinTimeInMinutes()
    {
        return tempTour.getMinTimeInMinutes();
    } 
    
    @Override
    public String toString()
    {
        return tempTour.getDescription()+"  " + tempTour.getCost() +"  " + tempTour.getMinTimeInMinutes();
    }
}
